class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<long long,long long> map;
        int n=nums1.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[(long long)nums1[i]+nums2[j]]++;
            }
        }

        int num=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                long long tem=(long long)nums3[i]+nums4[j];
                if(auto ele=map.find(-tem); ele!=map.end()){ 
                    num+=ele->second;
                }
            }
        }

        return num;
    }
};