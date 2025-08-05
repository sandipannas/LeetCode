class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        string count="";
        for(int i=1;i<nums.size()-1;i++){
          if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) {count+="a";} 
          if(nums[i]<nums[i-1] && nums[i]<nums[i+1]) { count+="b";}
          if(nums[i]==nums[i-1]){return false;}
        }
        if(count=="ab"){return true;}
        return false;
    }
};