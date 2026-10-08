class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int place_pt=0;

        int pre=nums[0]+1;

        for(int i=0;i<nums.size();i++){
            if(pre!=nums[i]){
                nums[place_pt]=nums[i];
                place_pt++; 
            }
            pre=nums[i];
        }

        return place_pt;
    }
};