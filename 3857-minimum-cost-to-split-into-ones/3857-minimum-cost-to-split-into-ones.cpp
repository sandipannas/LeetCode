class Solution {
public:
    int minCost(int n) {
        if(n==2 || n==1){return n-1;}
        return minCost(n-1)+(n-1);
    }
};