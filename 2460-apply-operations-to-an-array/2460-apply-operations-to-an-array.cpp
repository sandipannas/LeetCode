class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) { 
        vector<int> gg(nums.size(),0);
        int j=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1]){ nums[i]*=2; nums[i+1]=0; }
            if(nums[i]!=0){ gg[j]=nums[i]; j++;}
        }
        gg[j]=nums.back();
        
    return gg;}
};