class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int first=nums[0];
        int second=nums[1];
        int j=2;
        int ans=INT_MIN;
        int curr=2;
        while(j<nums.size()){
            cout<<"first "<<first<<" second"<<second<<endl;
           if(first+second!=nums[j]){
            curr=2;
           }
           else if(first+second==nums[j]){
             curr++;
           }
           first=nums[j-1];
           second=nums[j];
           j++;
           ans=max(ans,curr);
        }
        return ans;

    }
};