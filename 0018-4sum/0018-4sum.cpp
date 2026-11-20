class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;

        int fourth=nums.size()-1;
        if((long long)nums[0]+nums[1]+nums[2]+nums[3]>target){ return answer; }

        while(fourth>=3){
            if((long long)nums[fourth]+nums[fourth-1]+nums[fourth-2]+nums[fourth-3]<target){ break; }
            int third=fourth-1;

            while(third>=2){
                int first=0;
                int second=third-1;

                while(first<second){
                    long long sum=(long long)nums[first]+nums[second]+nums[third]+nums[fourth];
                    if(sum==target){ 
                        answer.push_back({nums[first],nums[second],nums[third],nums[fourth]});

                        int pre=nums[first];
                        while(first<second && pre==nums[first]){ first++; }

                        pre=nums[second];
                        while(first<second &&  pre==nums[second]){ second--; }
                     
                    }
                    else if(sum>target){
                        second--;
                    }
                    else{
                        first++;
                    }
                }
                int pre=nums[third];
                while(third>=2 && pre==nums[third]){ third--; }
            }
            int pre=nums[fourth];
            while(fourth>=3 && pre==nums[fourth]){ fourth--; }
        }
        return answer;
    }
};