class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        pair<int,int> big={-1,INT_MIN};        
        for(int i:nums){ 
            map[i]++; 
            if(big.second<map[i]){ big={i,map[i]}; }
        }
        return big.first;
    }
};