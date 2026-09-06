class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        char pre='@';

        int number=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int digit=c-'0';

            if( !isdigit(c) || i==s.size()-1 ){ 
                /////////////////////////////////////////
                if(c==' ' && i!=s.size()-1){ continue; }
                ////////////////////////////////////////
                if(i==s.size()-1 && c!=' '){ 
                    number=number*10+digit;
                }    
                //////////////////////////////////////////
                if(pre!='@'){
                    if(pre=='/')       nums.back()/=number;   
                    else if(pre=='*')  nums.back()*=number;
                    else if(pre=='+')  nums.push_back(number); 
                    else if(pre=='-')  nums.push_back(-number); 
                }
                else{
                    nums.push_back(number); 
                }
                ///////////////////////////////////////////
                number=0;
                pre=c;
            }
            else{
                number=(number*10)+digit;
            }
        }

        int answer=0;
        for(int i:nums) answer+=i;

        return answer;
    }
};