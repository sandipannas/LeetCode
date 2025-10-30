class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
            continue;

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            vector<int> pre={1,2,3};

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> curr={nums[i],nums[left],nums[right]};
                    if(pre!=curr){
                       res.push_back(curr); 
                    }
                    pre=curr;
                    left++;
                    right--;
                } 
                else if (sum < target) {
                    left++;
                } 
                else
                    right--;
            }
        }
        return res;
    }
};