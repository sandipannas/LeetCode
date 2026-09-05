class Solution {
public:
    string removeKdigits(string num, int k) {
       if(k>=num.size()) return "0";
       else if(k==0) return num;

       string answer=""; answer.reserve(num.size());

       for(char c:num){
            while(!answer.empty() && answer.back()>c && k!=0){
                    answer.pop_back();
                    k--;
            }
            if(answer.empty() && c=='0') continue; 

            answer.push_back(c);
       }

        while(!answer.empty() && k>0){
            answer.pop_back();
            k--;
        }

        return answer==""?"0":answer;
    }
};