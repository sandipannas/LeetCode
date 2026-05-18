class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> prefix(nums.size());
        
         int pro=1;
         for(int i=0;i<nums.size();i++){
            prefix[i]=pro;
            pro*=nums[i];
         }

         pro=1;
         for(int i=nums.size()-1;i>=0;i--){
            prefix[i]*=pro;
            pro*=nums[i];
         }

         return prefix;



    }
};