class Solution {
public:
    string clearDigits(string s) {
        string answer;

        for(char c:s){
            if(
               !answer.empty() && 
               isdigit(c)
              )
              {
                answer.pop_back();
              }
            else{
                answer.push_back(c);
            }
        }

        return answer;
    }
};