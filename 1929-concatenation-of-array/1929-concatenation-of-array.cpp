class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answer(nums.size()*2);

        for(int i;i<nums.size();i++){
            answer[i]=nums[i];
            answer[i+nums.size()]=nums[i];
        }

        return answer;
    }
};