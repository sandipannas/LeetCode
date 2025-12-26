class Solution {
public:
    bool isPerfectSquare(int num) {
       int left=1,right=(num/2)+1;
       while(left<=right){
         int mid=left+((right-left)/2);
         if((long long)mid*mid==num){
            return true;
         }
         else if((long long)mid*mid>num){
            right=mid-1;
         }
         else{
            left=mid+1;
         }
       }
       return false; 
    }
};