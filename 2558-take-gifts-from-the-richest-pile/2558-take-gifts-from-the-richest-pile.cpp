class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<double,vector<double>> pq;
        
        for(int i:gifts){
            pq.push(i);
        }

        while(k--){
            double tem=pq.top();
            tem=floor(sqrt(tem));
            pq.pop();
            pq.push(tem);
        }

        long long sum=0;
        while(pq.size()!=0){
            sum=sum+(long long)pq.top();
            pq.pop();
        }

        return sum;
    }
};