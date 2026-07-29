class MyQueue {
public:
    stack<int> one;
    stack<int> two;

    MyQueue() {}

    void push(int x) { one.push(x); }

    int pop() {
        if (two.empty())
            transfer(one, two);
        int answer = two.top();
        two.pop();
        return answer;
    }

    int peek() {
        if (two.empty())
            transfer(one, two);
        int answer = two.top();
        return answer;
    }

    bool empty() { return one.empty() && two.empty(); }

    void transfer(stack<int>& one, stack<int>& two) {
        while (one.size()) {
            two.push(one.top());
            one.pop();
        }
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