class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans=0;
        sort(ranks.begin(),ranks.end());
        int count=0;
        vector<int> gg(ranks.size(),0);
        long long activation=0;
        while(count!=cars)
        {   count++;
            gg[0]++;
            activation=ranks[0]*gg[0]*gg[0];
            if(count==cars){break;}
            for(int i=1;i<ranks.size();i++)
            {
                if(activation>=ranks[i]*(gg[i]+1)*(gg[i]+1)){
                    gg[i]++;
                    count++;
                }
                if(count==cars)
                {
                    break;
                }
            }
        }
        return activation;
    }
};