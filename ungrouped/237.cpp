#include "../include.h"

void deleteNode(ListNode* node) {
    *node = *node->next;
}