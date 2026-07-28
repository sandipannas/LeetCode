class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> stk;

        for(string s:logs){
            if(s=="../" && stk.size()!=0){
                stk.pop();
            }
            else if(s.front()!='.'){
                stk.push(1);
            }
        }

        return stk.size();
    }
};