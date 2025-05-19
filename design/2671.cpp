class FrequencyTracker {
public:

    map<int, int> num;
    int freq[100001] = {0};

    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(num.find(number) != num.end()) {
            freq[num[number]]--;
            num[number]++;
            freq[num[number]]++;
        } else {
            num[number] = 1;
            freq[1]++;
        }
    }
    
    void deleteOne(int number) {
        if(num.find(number) != num.end() && num[number] != 0) {
            freq[num[number]]--;
            num[number]--;
            freq[num[number]]++;
        }   
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */