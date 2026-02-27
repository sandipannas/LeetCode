class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int left=0;
      int right=0;

      while(right<nums.size() && nums[right]<0){
        right++;
      }

      vector<int> ans;
      left=right-1;
      while(left>=0 && right<nums.size()){
        if(nums[left]*nums[left]<nums[right]*nums[right]){
            ans.push_back(nums[left]*nums[left]);
            left--;
        }
        else{
            ans.push_back(nums[right]*nums[right]);
            right++;
        }
      }

      while(left>=0){
        ans.push_back(nums[left]*nums[left]);
        left--;
      }

      while(right<nums.size()){
        ans.push_back(nums[right]*nums[right]);
        right++;
      }

      return ans;
    }
};