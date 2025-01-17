class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sy=1;
        for(int i=0;i<derived.size();i++){
        if(derived[i]==1){sy=(~sy);} 
        }

        if(sy==1){ return true; }
        return false;
    }
};