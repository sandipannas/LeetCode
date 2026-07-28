class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;

        for(string s:logs){
            if(s=="../" && stk.size()!=0){
                stk.pop();
            }
            else if(s.back()=='/' && s.front()!='.'){
                stk.push("s");
            }
        }

        return stk.size();
    }
};