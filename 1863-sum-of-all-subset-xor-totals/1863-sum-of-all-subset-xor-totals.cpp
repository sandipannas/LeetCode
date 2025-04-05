class Solution {
public:
    int reccur(vector<int>& nums,int xo,int irr){
        if(irr>=nums.size()){
            return xo;
        }
            int with=reccur(nums,nums[irr]^xo,irr+1);
            int without=reccur(nums,xo,irr+1);
        return with+without;
        
    }
    int subsetXORSum(vector<int>& nums) {
        return reccur(nums,0,0);
    }
};