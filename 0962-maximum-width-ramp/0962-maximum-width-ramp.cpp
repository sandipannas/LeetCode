class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> stk;

        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty() || nums[stk.back()] > nums[i]) stk.push_back(i);
        }

        int ramp = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] <= nums[i]) {
                ramp = max(i - stk.back(), ramp);
                stk.pop_back();
            }

            if (stk.empty())
                break;
        }
        return ramp;
    }
};