class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1; int curr=0; int count=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(map.count(curr-k)){
                count+=map[curr-k];
            }
            map[curr]++;
            
        }
        return count;
    }
};