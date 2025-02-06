class Solution {
public:
    int tupleSameProduct(vector<int>& n) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n.size(); i++)
            for (int j = i + 1; j < n.size(); j++) {
                int product = n[i] * n[j];
                ans += 8 * mp[product];
                mp[product]++;
            }
        return ans;
    }
};