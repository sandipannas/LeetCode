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

        while(set.count(left)){
            count++; set.erase(left); left--;
        }
        while(set.count(right)){
            count++; set.erase(right); right++;
        }

        big=max(big,count);
        count=1;
       }

       return big;
    }
};