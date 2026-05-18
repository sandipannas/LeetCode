class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> set;
       int count=1;
       int big=0;

       for(int i:nums){
            set.insert(i);
       }

       for(int i:set){
        
        int right=i+1;
        int left=i-1;
        int flag_left=1;
        int flag_right=1;

        while(set.count(left) || set.count(right)){
            if(flag_left && set.count(left)){count++; set.erase(left); left--;}
            else{ flag_left=0; }
            if(flag_right && set.count(right)){count++; set.erase(right); right++;}
            else{ flag_right=0; }
        }
        big=max(big,count);
        count=1;
       }

       return big;
    }
};