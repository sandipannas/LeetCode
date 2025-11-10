class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char i:s){
            if(!stk.empty()){
                if(i==')' && stk.top()=='('){ stk.pop(); }
                else if(i=='}' && stk.top()=='{'){ stk.pop(); }
                else if(i==']' && stk.top()=='['){ stk.pop(); }
                else{ stk.push(i); }
            }
            else{ stk.push(i); }
        }
        return stk.empty()?true:false;
    }
};