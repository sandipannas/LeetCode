class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0,ed=nums.size()-1;
        while(st<=ed){
            int mid=(ed+st)/2;
            int prev=(mid==0)? -1:nums[mid-1];
            int next=(mid==nums.size()-1)? -1:nums[mid+1];
            cout<<prev<<" "<<nums[mid]<<" "<<next<<endl;
            cout<<nums[st]<<" st "<<nums[mid]<<" mid "<<nums[ed]<<" ed "<<endl;
            if(nums[mid]!=prev && nums[mid]!=next){
                return nums[mid];
            }
            else if(mid%2==0 && prev==nums[mid]){ 
                        ed=mid; }
            else if(mid%2==0 && next==nums[mid]){
                        st=mid; }
            else if(mid%2==1 && next==nums[mid]){ 
                        ed=mid-1; }
            else if(mid%2==1 && prev==nums[mid]){
                        st=mid+1; }
        }
    return -1;}
};