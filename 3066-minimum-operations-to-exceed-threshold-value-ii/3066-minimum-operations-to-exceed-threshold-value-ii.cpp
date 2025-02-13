class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long, vector<long>, greater<long> > gg;
        for(int i:nums){
        gg.push(i);
        }
        long count=0;
        while(gg.top()<k){
            long a=gg.top();
            gg.pop();
            long b=gg.top();
            gg.pop();
            long m1=min(a,b)*2;
            long m2=max(a,b);
            gg.push(m1+m2);
            count++;

        }
        return count;
    }
    
};