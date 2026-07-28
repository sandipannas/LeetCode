class MyStack {
public:
    queue<int> one;
    queue<int> two;

    MyStack() {
        
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        return transfer(one,two,0);
    }
    
    int top() {
        return transfer(one,two,1);
        
    }
    
    bool empty() {
        if(one.size()==0) return 1;
        return 0;
    }

    int transfer(queue<int>& one,queue<int>& two,int flag){
        while(one.size()!=1){
            two.push(one.front());
            one.pop();
        }

        int tem=one.front();
        one.pop();

        if(flag){
           two.push(tem); 
        }

        while(!two.empty()){
            one.push(two.front());
            two.pop();
        }

        return tem;
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