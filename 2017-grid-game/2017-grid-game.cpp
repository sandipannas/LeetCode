class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        if(n==1)
        {
            return 0;
        }
        vector<long> pre_up;
        vector<long> pre_do;
        long sum2=0;
        long sum1=0;
        for(int i=n-1;i>=0;i--)
        {
          sum1+=grid[0][i];
          sum2+=grid[1][n-1-i];
          pre_up.insert(pre_up.begin(),sum1);
          pre_do.push_back(sum2);
        }
        //pre_up[0]-=grid[0][0];
        //pre_do[n-1]-=grid[1][n-1];
        pre_up.erase(pre_up.begin()+0);
        pre_do.pop_back();

        pre_up.push_back(0);
        pre_do.insert(pre_do.begin()+0,0);

        long ans=LONG_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,max(pre_up[i],pre_do[i]));
        }
         
        return ans;
    }
};