class Solution {
public:
    string removeKdigits(string num, int k) {
       //bullshit edge cases
       if(k>=num.size()){
        return "0";
       }
       else if(k==0){ return num; }
       
        //buid a montonic stack increases only
        // handle leading zeros 
        // after passing the num string through monotonic stack if k remains start excluding from the back;

        string answer="";

        for(char c:num){
        while(!answer.empty() && answer.back()>c && k!=0){
                    answer.pop_back();
                    k--;
        }

        if(answer.empty() && c=='0'){ continue; }

        answer.push_back(c);
        }

        while(!answer.empty() && k--){
            answer.pop_back();
        }

        return answer==""?"0":answer;
    }
};