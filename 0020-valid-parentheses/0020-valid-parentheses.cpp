class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char i : s){
            if(i=='(')      stk.push(')');
            else if(i=='{') stk.push('}'); 
            else if(i=='[') stk.push(']'); 
            else{ 
                if(stk.empty() || i!=stk.top()) return false; 
                else{ stk.pop(); }  
            }
        }

        if(!stk.empty()) return false;
        return true;
    }
};