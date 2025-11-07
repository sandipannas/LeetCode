class Solution {
public:
    bool check(int index,long long curr,vector<int>& nums,vector<int>& dp){
        if(curr==0){ return true; }
        if(index>=nums.size()){ return false; }
        //take
        bool take=curr<nums[index]?false:check(index+1,curr-nums[index],nums,dp);
        //not take
        bool nTake=check(index+1,curr,nums,dp);

        return take || nTake;
    }

    bool canPartition(vector<int>& nums) {
       long long total=0;
       vector<int> dp(5);
       for(int i:nums){
        total+=(long long)i;
       }
       if(total%2==1){ return false; }
       else { return check(0,total/2,nums,dp); } 
    }
};