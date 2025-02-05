class Solution {
public:
    vector<vector<int>> gg;
    vector<int> quad;
    void ans(vector<int>& n,long long target,int k,int st)
    {
        if(k!=2)
        {
            for(int i=st;i<n.size()-k+1;i++)
            { 
              if(i!=st && n[i]==n[i-1]){ continue; } //to avoid duplicates;
              quad.push_back(n[i]);
              ans(n,target-n[i],k-1,i+1);
              quad.pop_back();
            }
        }
        else{
        int s=st;
        int e=n.size()-1;
        while(s<e)
        {   if(s!=st && n[s]==n[s-1]){ s++; }
            else if(e!=n.size()-1 && n[e]==n[e+1]){ e--;}
            else if(n[s]+n[e]==target)
            {
                vector<int> tem;
                copy(quad.begin(),quad.end(),back_inserter(tem));
                tem.push_back(n[s]);
                tem.push_back(n[e]);
                gg.push_back(tem);
                s++;
            }
            else if(n[s]+n[e]>target) { e--; }
            else if(n[s]+n[e]<target) { s++; }
            else {break;}
        }}
    }
    vector<vector<int>> fourSum(vector<int>& n, int target) {
        if(n.size()<4) { return {}; }
        sort(n.begin(),n.end());
        ans(n,target,4,0);
        return gg;   
    }
};