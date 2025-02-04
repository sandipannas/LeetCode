class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int boat=0,st=0,ed=p.size()-1;
        int count=0,left=p.size();
        sort(p.begin(),p.end());
        while(st<ed)
        {
          if(p[st]+p[ed]<=limit)
          {
            st++; ed--; count++; left-=2;
          }
          else{
            ed--;
          }
        }
        return count+left;
        }
};