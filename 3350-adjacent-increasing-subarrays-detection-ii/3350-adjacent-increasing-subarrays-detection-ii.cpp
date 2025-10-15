class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        unordered_map<int,int> map;
        int curr=0;
        int pre=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pre){
                curr++;
            }
            else{
                curr=1;
            }
            pre=nums[i];
            map[i]=curr;
        }
        int ansMax=INT_MIN;

        for(auto &i:map){
            int left=1;
            int right=i.second;

            int index=i.first;

            while(left<=right){
                int k=left+((right-left)/2);
                if(map.count(index+k) && map[index+k]>=k){
                    left=k+1;
                    ansMax=max(ansMax,k);
                }
                else{
                    right=k-1;
                }
            }
        }
        return ansMax;
    }
};