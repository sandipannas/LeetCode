class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0,sum2=0;
        for(int i:nums1){sum1^=i;}
        for(int i:nums2){sum2^=i;}
        if((nums1.size()%2)==0 && (nums2.size()%2)==0){return 0;}
        if((nums1.size()%2)==0){return sum1;}
        if((nums2.size()%2)==0){return sum2;}
        return sum1^sum2;
    }
};