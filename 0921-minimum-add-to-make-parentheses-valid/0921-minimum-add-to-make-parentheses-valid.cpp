class Solution {
public:
    int minAddToMakeValid(string s) {
        string stk="";
        for(char c:s){
            if(!stk.empty() && stk.back()=='(' && c==')'){
                stk.pop_back();
            }
            else{
                stk.push_back(c);
            }
        }
        return stk.size();
    }
};