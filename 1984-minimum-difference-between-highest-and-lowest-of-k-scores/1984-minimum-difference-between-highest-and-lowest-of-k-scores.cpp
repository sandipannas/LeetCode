class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1){ return 0; }
        sort(nums.begin(),nums.end());
        int miin=INT_MAX;
        for(int i=0;i<nums.size();i++){
          if(i+k-1<nums.size()){
            miin=min(miin,nums[i+k-1]-nums[i]);
          }
        }
        return miin;
    }
};