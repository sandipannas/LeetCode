class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> map(nums.size());
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

        for(int i=0;i<map.size();i++){
            int left=1;
            int right=map[i];

            int index=i;

            while(left<=right){
                int k=left+((right-left)/2);
                if(index+k<map.size() && map[index+k]>=k){
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