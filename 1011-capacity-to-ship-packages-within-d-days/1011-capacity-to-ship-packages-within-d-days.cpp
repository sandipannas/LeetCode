class Solution {
public:

    int fullfill(vector<int>& weights,int days,int limit){
        int count=0;
        int sum=0;
        for(int i:weights){
            if(sum+i>limit){
               count++;
               sum=i;
            }
            else { sum+=i; }
        }
        if(count+1>days){ return 0; }
        return 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int st=-1,ed=0;
        for(int i:weights){
            ed+=i;
            if(i>st){ st=i; }
        }
        
        int mini=ed;
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(fullfill(weights,days,mid)){
                mini=mid;
                ed=mid-1;
            }
            else{
                st=mid+1;
            }
        }

        return mini;

    }
};