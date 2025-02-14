class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int st=0,ed=potions.size()-1;
            int mid=(st+ed)/2;
            long long tem=1;
            while(st<=ed){
                mid=(st+ed)/2;
                tem=(long long)(spells[i])*(long long)(potions[mid]);
                if(tem>=success)
                {
                  ed=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            tem=(long long)(spells[i])*(long long)(potions[mid]);
            if(st>=potions.size()){spells[i]=0;}
            else if(ed<=-1){spells[i]=potions.size();}
            else if(tem>=success){spells[i]=potions.size()-mid;}
            else{
               spells[i]=potions.size()-mid-1; 
            }
        }
    return spells;}
};