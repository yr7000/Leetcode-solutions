class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> freqStack;
    int maxFrequency = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFrequency = max(maxFrequency,freq[val]);
        freqStack[freq[val]].push(val);
    }
    
    int pop() {
        int result = freqStack[maxFrequency].top();
        freqStack[maxFrequency].pop();
        freq[result]--;
        if(freqStack[maxFrequency].empty()) maxFrequency--;
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */