class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0,pre=0,maxi=0;
        for(int i:nums)
        {
            if(pre<=i){sum+=i; maxi=max(sum,maxi);}
            else{ sum=i;}
            pre=i;
        }
    return maxi;}
};