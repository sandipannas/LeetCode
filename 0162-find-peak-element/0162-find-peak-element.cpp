class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st=0,ed=nums.size()-1;
        while(st<=ed)
        {   int mid=(st+ed)/2;
            long prev=(mid==0)?LONG_MIN:nums[mid-1];
            long next=(mid==nums.size()-1)?LONG_MIN:nums[mid+1];

            if(nums[mid]>prev && nums[mid]>next){
                return mid;
            }
            else if(nums[mid]>prev)
            {
                st=mid+1;
            }
            else{
                ed=mid-1;
            }
        }
   return -1;}
};