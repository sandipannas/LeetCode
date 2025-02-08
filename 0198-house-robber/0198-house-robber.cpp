class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        int n=nums.size();
        nums.push_back(0);
        vector<int> dp(n+1,-1);
        int ver1=nums[0];
        int ver2=max(nums[1],nums[0]);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=max(ver2,ver1+nums[i]);
            ver1=ver2;
            ver2=ans;
        }
        return ans;
    }
};