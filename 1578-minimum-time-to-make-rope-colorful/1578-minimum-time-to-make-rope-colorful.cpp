class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int n=c.size(),st=0,ed=1,cost=0;
        while(ed<n)
        {
            if(c[st]==c[ed])
            {
             if(nt[st]<=nt[ed]){ cost+=nt[st]; }
             else{ cost+=nt[ed];
                   swap(nt[st],nt[ed]);
                 }
            }
            st++; ed++;
        }
    return cost;}
};