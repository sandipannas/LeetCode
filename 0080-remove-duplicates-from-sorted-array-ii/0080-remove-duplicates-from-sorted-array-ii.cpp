class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right=0;
        int count=1;

        while(right<nums.size()){
            if(count<=2){
                nums[left]=nums[right];
                left++;
            }
            
            right++;
            
            if(nums[right-1]==nums[right]){ count++; }
            else{ count=1; }
        }

        return left;
    }
};