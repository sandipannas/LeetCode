class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long wait=customers[0][1];
        for(int i=1;i<customers.size();i++){
            
            long long tem=customers[i-1][1]-(customers[i][0]-customers[i-1][0]);
            long long curr_wait=tem<=0?customers[i][1]:customers[i][1]+tem;

            wait+=curr_wait;

            
            customers[i][1]=curr_wait;
            
        
            
        }
        return (double)(wait)/(double)(customers.size());
    }
};