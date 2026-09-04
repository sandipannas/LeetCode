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
            //this while loop keeps the string monotonic
            while(!answer.empty() && answer.back()>c && k!=0){
                    answer.pop_back();
                    k--;
            }
            
            //removing leading zeros doesnt affect k
            if(answer.empty() && c=='0'){ continue; }

            answer.push_back(c);
        }

        //we still have some leftover k to work with
        while(!answer.empty() && k>0){
            answer.pop_back();
            k--;
        }

        //the string can be empty due to the zeros init 
        return answer==""?"0":answer;
    }
};