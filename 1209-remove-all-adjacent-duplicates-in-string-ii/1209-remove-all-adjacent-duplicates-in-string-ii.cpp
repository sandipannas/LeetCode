class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;

        for(char c:s){
            if(stk.empty() || stk.back().first!=c) stk.push_back({c,1});

            else if(stk.back().first==c){ 
                if(stk.back().second+1==k) {
                    stk.pop_back();
                }
                else{
                    stk.back().second+=1;
                }
            }
        }

        string answer="";
        for(auto& both : stk){
            int count=both.second;
            while(count--){
                answer+=both.first;
            }
        }

        return answer;
    }
};