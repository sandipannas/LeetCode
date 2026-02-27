class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()<=1){ return nums.size();}

      int left=0;
      int right=1;

      while(left<nums.size() && right<nums.size()){
        if(nums[left]!=nums[right]){
            left++;
            right++;
        }
        else{
            while(right<nums.size() && nums[left]==nums[right]){
              right++;
            }
            
            if(left<nums.size() && right<nums.size()){
                left++;
                nums[left]=nums[right];
            }
        }
      }  
       return left==nums.size()?left:left+1; 
    }
};