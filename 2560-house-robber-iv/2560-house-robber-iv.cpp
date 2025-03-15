class Solution {
public:
    bool robb(vector<int>& nums,int mid,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }

        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=1;
        int r = *max_element(nums.begin(),nums.end());
        int anss=r;

        while(l<=r){
            int mid = (l+r)/2;
            if(robb(nums,mid,k)){
                anss=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return anss;
    }
};