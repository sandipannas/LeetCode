class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> gg;
        for(int i:nums){
           gg[i]++;
        }
        for(auto& pair:gg)
        {
            if(pair.second%2!=0){ return false;}
        }
        return true;
    }
};