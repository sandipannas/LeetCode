class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long> gg;
        long n=nums.size();
        for(int i=0;i<n;i++)
        { 
          gg[nums[i]-i]++;
        }
        long long total=n*(n-1LL)/2;
        cout<<total<<endl;
        for(auto& [j,i]:gg)
        {   
            if(i>1){ total-=i*(i-1LL)/2; }
        }
        return total;

    }
};