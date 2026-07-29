class Solution {
public:
    string clearDigits(string s) {
        string answer;

        for(char c:s){
            if(
               !answer.empty() && 
               (answer.back()<48 || answer.back()>57) &&
               c>=48 && c<=57
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