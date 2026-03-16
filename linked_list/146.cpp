#include "include.h"

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k = 0, int v = 0) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;           // key → Node*
    Node *head, *tail;                         // dummy head and tail nodes

    // Insert a node right after head (most recently used)
    void insertToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Move a node to the front (most recently used)
    void moveToHead(Node* node) {
        if (node == head->next) return;        // already at front, no need to move
        
        // Remove from current position
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // Insert after head
        insertToFront(node);
    }

    // Remove the tail node (least recently used)
    void removeTail() {
        Node* node = tail->prev;
        cache.erase(node->key);
        node->prev->next = tail;
        tail->prev = node->prev;
        delete node;   // remember to free memory
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    // Remember to free all nodes in the destructor (avoid memory leak)
    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        Node* node = cache[key];
        moveToHead(node);           // move to front
        return node->value;
    }
    
    void put(int key, int value) {
        // If key exists → update value and move to front
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
            return;
        }
        
        // New key → create new node
        Node* node = new Node(key, value);
        cache[key] = node;
        
        // Insert at front
        insertToFront(node);
        
        // If over capacity → remove the least recently used
        if (cache.size() > capacity) {
            removeTail();
        }
    }
};
