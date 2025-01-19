class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long fake=0;
        for(int i=0;i<arr.size();i++)
            {
                fake+=abs(arr[i]-brr[i]);
            }
        
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        long long sum=0;
        
        for(int i=0;i<arr.size();i++)
            {
                sum+=abs(arr[i]-brr[i]);
            }
        return min(k+sum,fake);
    }
};