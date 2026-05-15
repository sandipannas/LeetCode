class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int mul=1; vector<int> answer;

        for(int i:nums){if(i==0){zero++;}else{mul*=i;}}

        for(int i:nums){
            if(zero>1){
                answer.push_back(0);
            }
            else if(zero==1){ 
                if(i!=0){
                    answer.push_back(0);
                }
                else{
                    answer.push_back(mul);
                }
            }
            else{
                answer.push_back(mul/i);
            }
        }
        return answer;
    }
};