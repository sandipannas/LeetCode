class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char i:s){
            if(ranges::contains(array{')','}',']'},i) && stk.empty()){
                return false;
            }
            else if(
                ( i==')' && stk.top()!='(' ) || 
                ( i=='}' && stk.top()!='{' ) || 
                ( i==']' && stk.top()!='[' )) {
                    return false;
            }
            else if(
                ( i==')' && stk.top()=='(' ) || 
                ( i=='}' && stk.top()=='{' ) || 
                ( i==']' && stk.top()=='[' )
            ){
                stk.pop();
            }
            else{
                stk.push(i);
            }

        }
        if(!stk.empty()){ return false;}
        return true;
    }
};