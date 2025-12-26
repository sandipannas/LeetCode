class Solution {
public:
    int arrangeCoins(int n) {
        int st=1,ed=n;
        while(st<=ed){
            int mid=st+((ed-st)/2);
            long long tem = (long long)mid*((long long)mid+1)/2;
            if(tem<=n){
                st=mid+1;
            }
            else{
                ed=mid-1;
            }
        }
        return ed;
    }
};