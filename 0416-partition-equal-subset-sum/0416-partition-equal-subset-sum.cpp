class Solution {
public:
    int flag=0;
    void check(int first,int second,vector<int>& nums,int irr)
    {   
        if(flag==1){ return; }
        if(irr>=nums.size()){
            if(first==second){
                flag=1;
            }
            return; 
        }

        check(first + nums[irr],second,nums,irr+1);
        check(first,second + nums[irr],nums,irr+1);
        return;
    }

    bool canPartition(vector<int>& nums) {
        check(0,0,nums,0);
        if(flag==1){
            return true;
        }
        return false;
    }
};