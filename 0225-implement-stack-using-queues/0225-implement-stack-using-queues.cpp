class MyStack {
public:
    queue<int> one;

    MyStack() {
        
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        return transfer(one,0);
    }
    
    int top() {
        return transfer(one,1);  
    }
    
    bool empty() {
        return one.empty();
    }

    int transfer(queue<int>& one,int top){
        int n=one.size()-1;
        while(n--){
          one.push(one.front());
          one.pop();
        }

        int answer=one.front();
        one.pop(); 
        
        if(top) one.push(answer);

        return answer;
    }

        
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */