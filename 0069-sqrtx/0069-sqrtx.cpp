class Solution {
public:
    int mySqrt(int x) {
        long long left=0;
        long long right=(x%2==0)?x/2:(x/2)+1;
        while(left<=right){
            long long mid=left+((right-left)/2);
            if(mid*mid==x)return(mid);
            if(mid*mid>x){
                right=mid-1;
            }
            else if(mid*mid<x){
                left=mid+1;
            }
        }
        cout<<left<<right;
        return right;
    }
};