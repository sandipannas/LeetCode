class Solution {
public:
    int minLength(string s) {
        string answer;

        for(char c:s){
            if(!answer.empty() && 
               ((answer.back()=='A' && c=='B') ||
               (answer.back()=='C' && c=='D')))
            {
                answer.pop_back();
            }
            else{
                answer.push_back(c);
            }
        }
        return answer.size();
    }
};