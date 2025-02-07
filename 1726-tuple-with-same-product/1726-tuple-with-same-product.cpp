class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if(nums.size()<4){return 0;}
        unordered_map<int,int> gg;
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                gg[nums[i]*nums[j]]++;
            }
        }
        for(auto& i:gg)
        {   
            if(i.second>1){
            count+=tgamma(i.second+1)/tgamma(i.second-1);
        }}
        return count*4;
    }
};