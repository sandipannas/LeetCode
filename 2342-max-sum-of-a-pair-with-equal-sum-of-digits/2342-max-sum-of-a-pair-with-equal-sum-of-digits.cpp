class Solution {
public:
    int cosum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    } 
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>> gg;
        for(int i:nums)
        {
            gg[cosum(i)].push(i);
        }
        int maxi=-1;
        for(auto& i:gg)
        {
            if(i.second.size()>1)
            {
              int a=i.second.top();
              i.second.pop();
              int b=i.second.top();
              maxi=max(a+b,maxi);
            }
        }
        return maxi;
    }
};