class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());

        int st=0,left=0;
        while(st<t.size() && left<p.size())
        {
            if(t[st]>=p[left]){ st++; left++;}
            else{ st++; }
        }

    return left;}
};