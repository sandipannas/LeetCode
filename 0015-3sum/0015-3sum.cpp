class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};

        vector<vector<int>> answer;

        sort(nums.begin(),nums.end());
        int third=nums.size()-1;

        while(third>=2){
            int first=0;
            int second=third-1;
            while(first<second){
                int sum=nums[first]+nums[second]+nums[third];
                if(sum==0){ 
                    answer.push_back( {nums[first],nums[second],nums[third]} );
                    int pp=nums[second];
                    while(nums[second]==pp && first<second){ second--;}
                }
                else if(sum>0) second--;
                else first++;
            }
            int pre=nums[third];
            while(nums[third]==pre && third>=2){ third--;}
        }

        return answer;
    }
};