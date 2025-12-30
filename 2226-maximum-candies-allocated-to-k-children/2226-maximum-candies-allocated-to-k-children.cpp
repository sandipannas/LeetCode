class Solution {
public:
    int fullfill(vector<int> candies,long long k,long long mid){
        long long total=0;
        for(int i:candies){
          total+=i/mid;
        }
        if(total<k){ return 0; }
        return 1;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = 0;
        for(long long candy:candies){
            total_candies+=candy;
        }

        long long st=1,ed=total_candies/k;
        long long maxi=0;
        while(st<=ed){
            long long mid=st+(ed-st)/2;
            //cout<<" for mid "<<mid<<endl;
            if(fullfill(candies,k,mid)){
                //cout<<"condition pass "<<endl;
                st=mid+1;
                maxi=mid;
            }
            else{
                //cout<<"condition failed"<<endl;
                ed=mid-1;
            }
        }

        return maxi;
    }
};