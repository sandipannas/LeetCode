class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;

        int left=1;
        int right=1;

        while(right<nums.size()){
            if(nums[right]!=nums[right-1]){
                nums[left++]=nums[right];
            }
            right++;
        }

        return left;
    }
};