class Solution {
public:
    int tupleSameProduct(vector<int>& n) {
        unordered_map<int, int> gg;
        int ans = 0;
        for (int i = 0; i < n.size(); i++)
            for (int j = i + 1; j < n.size(); j++) {
                int product = n[i] * n[j];
                ans += 8 * gg[product];
                gg[product]++;
            }
        return ans;
    }
};