class FreqStack {
public:

    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;

    int max_freq = 0;

    FreqStack() { }

    void push(int val) {
        
        int f = ++freq[val];
        group[f].push(val);

        max_freq = max(max_freq, f);
    }
    
    int pop() {
        int val = group[max_freq].top();

        group[max_freq].pop();

        freq[val]--;

        if(group[max_freq].empty())
        max_freq--;

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */