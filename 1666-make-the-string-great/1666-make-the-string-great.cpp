class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(!stk.empty() && abs((int)stk.top()-(int)s[i])==32 )
                stk.pop();
            else{ stk.push(s[i]); }
        }
        s="";
        while(!stk.empty()){
            s.push_back(stk.top()); stk.pop();
        }
        
        reverse(s.begin(),s.end());

        return s;

    }
};