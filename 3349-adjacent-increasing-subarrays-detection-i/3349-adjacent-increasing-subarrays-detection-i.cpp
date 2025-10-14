class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int curr=0;
        int pre=INT_MIN;
        unordered_set<int> set;

        for(int i=0;i<nums.size();i++){
           if(nums[i]>pre){
            curr++;
           }
           else{
            curr=1;
           }
           if(curr>=k){
             set.insert(i);
           }
           pre=nums[i];
        }
        for(int i:set){
            if(set.count(i-k)){
                return true;
            }
        }
        return false;
    }
};