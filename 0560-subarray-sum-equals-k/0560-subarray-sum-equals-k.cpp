class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int presum=0; int count=0; map[0]=1;
        for(int i:nums){
            presum+=i;
            if(map.count(presum-k)){
                count+=map[presum-k];
            }
            map[presum]++;
        }
        return count;
    }
};