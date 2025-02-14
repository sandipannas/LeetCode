class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
      int prev=-1;
      for(int i:nums){
        if(i%2==prev){ return false;}
        prev=i%2;
      }
      return true;  
    }
};