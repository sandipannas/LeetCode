class NumArray {
public:
    vector<int> gg;
    NumArray(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
            gg.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int minus=(left<=0)?0:gg[left-1];
        int total=gg[right];
        return total-minus;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */