class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int index_to_insert=1;
         int current_No=nums[0];
         for(int i=1;i<nums.size();i++){
            if(nums[i]!=current_No){
                nums[index_to_insert]=nums[i];
                index_to_insert++;
                current_No=nums[i];
            }
         }
        return index_to_insert;
    }
};