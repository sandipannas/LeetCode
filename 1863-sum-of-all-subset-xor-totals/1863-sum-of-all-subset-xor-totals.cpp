class Solution {
public:
    int answer=0;
    void reccur(vector<int>& nums,int xo,int irr){
        if(irr>=nums.size()){
            answer+=xo;
            cout<<xo<<endl;
            return;
        }
            reccur(nums,nums[irr]^xo,irr+1);
            reccur(nums,xo,irr+1);
        
    }
    int subsetXORSum(vector<int>& nums) {
        reccur(nums,0,0);
        return answer; 
    }
};