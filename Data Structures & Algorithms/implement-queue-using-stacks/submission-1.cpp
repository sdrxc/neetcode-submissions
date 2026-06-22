class MyQueue {
public:

// Use two stacks:
// in → for pushing new elements.
// out → for popping/peeking elements.
// When out is empty, transfer all elements from in to out.

    void transfer()
    {
        while(!in_st.empty())
        {
            out_st.push(in_st.top());
            in_st.pop();
        }
    }

    stack<int> in_st, out_st;

    MyQueue() {
        
    }
    
    void push(int x) {
        in_st.push(x);
    }
    
    int pop() {
        int val = peek();
        out_st.pop();
        return val;
    }
    
    int peek() {
        if(out_st.empty())
        {
            transfer();
        }
        return out_st.top();
    }

    bool empty() {
        return in_st.empty() && out_st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */