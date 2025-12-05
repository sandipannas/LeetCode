class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> prefix(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++)
            {
                sum+=nums[i];
                prefix[i]=sum;
            }
        sum=0;
        for(int i=0;i<nums.size()-1;i++)
            {
                if(abs(prefix[nums.size()-1]-(2*prefix[i]))%2==0)
                {
                    sum++;
                }
            }
    return sum;}
};