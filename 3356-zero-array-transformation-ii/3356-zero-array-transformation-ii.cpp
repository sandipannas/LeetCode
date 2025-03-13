class Solution {
public:
    int minZeroArray(vector<int>& a, vector<vector<int>>& q) {
        const int n = a.size();
        const int m = q.size();
        int* diff = (int*)calloc(n + 1, sizeof(int));
        int k = 0;
        for (int i = 0, s = 0; i < n; ++i) {
            while (s + diff[i] < a[i]) {
                if (k == m) {
                    free(diff);
                    return -1;
                }
                const int l = q[k][0];
                const int r = q[k][1];
                const int v = q[k][2];
                ++k;
                if (r < i) continue;
                diff[max(l, i)] += v;
                diff[r + 1] -= v;
            }
            s += diff[i];
        }
        free(diff);
        return k;
    }
};