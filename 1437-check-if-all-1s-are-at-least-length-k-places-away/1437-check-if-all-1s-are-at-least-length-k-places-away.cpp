class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count=nums.size();
        for(int i:nums){
            if(i==1 && count<k){ return false;}
            else if(i==1){ count=0; }
            else { count++; }
        }
        return true;
    }
};