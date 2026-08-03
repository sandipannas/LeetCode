class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(string s:tokens){
            if(s=="+"){ 
                int add=stk.top();
                stk.pop();
                stk.top()+=add; 
            }
            else if(s=="-"){ 
                int add=stk.top();
                stk.pop();
                stk.top()-=add; 
            }
            else if(s=="*"){ 
                int add=stk.top();
                stk.pop();
                stk.top()*=add; 
            }
            else if(s=="/"){ 
                int add=stk.top();
                stk.pop();
                stk.top()/=add; 
            }
            else{
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};