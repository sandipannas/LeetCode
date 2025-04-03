class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxDiff = 0;
        int maxm = nums[0];
        long long result = 0;

        for(int i=1;i<nums.size();i++){
            long long curr = 1LL * maxDiff*nums[i];
            result = ((result<curr) ? curr:result);

            maxDiff = max(maxDiff, maxm-nums[i]);
            maxm = max(maxm,nums[i]);
        }

        return result;
    }
};