class Solution {
public:
    string makeGood(string s) {
        string answer="";
        for(int i=0;i<s.size();i++){
            if(answer.size()!=0 && abs(answer.back()-s[i])==32 )
            { answer.pop_back(); }
            else{ answer.push_back(s[i]); }
        }

        return answer;

    }
};