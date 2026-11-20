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

            if(nums[third]<0 || nums[second]+nums[third]<0){ break; }

            while(first<second){
                int sum=nums[first]+nums[second]+nums[third];
                if(sum==0){ 
                    answer.push_back( {nums[first],nums[second],nums[third]} );
                    
                    int pp=nums[second];
                    while(first<second && nums[second]==pp){ second--;}

                    pp=nums[first];
                    while(first<second && nums[first]==pp){ first++; }
                }
                else if(sum>0) second--;
                else first++;
            }
            int pre=nums[third];
            while(third>=2 && nums[third]==pre){ third--;}
        }

        return answer;
    }
};