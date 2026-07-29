class Solution {
public:
    int minLength(string s) {
        string answer;

        for(char i:s){
            if(!answer.empty() && 
               ((answer.back()=='A' && i=='B') ||
               (answer.back()=='C' && i=='D')))
            {
                answer.pop_back();
            }
            else{
                answer.push_back(i);
            }
        }
        return answer.size();
    }
};