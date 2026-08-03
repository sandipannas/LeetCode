class MinStack {
public:
    stack<int> stk;
    stack<int> stkmin;

    MinStack() {}

    void push(int value) {
        if (stk.empty()) {
            stk.push(value);
            stkmin.push(value);
        } else {
            if(value<=stkmin.top()){ stkmin.push(value); }
            stk.push(value);
        }
    }

    void pop() { 
        if(stkmin.top()==stk.top()){ stkmin.pop(); }
        stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return stkmin.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */