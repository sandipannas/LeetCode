#define ll long long
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        ll n = grid.size(), m = grid[0].size();
        priority_queue<pair<ll, pair<ll, ll>>> pq;
        pq.push({-grid[0][0], {0, 0}});
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        while (!pq.empty()) {
            auto [mx, cord] = pq.top(); pq.pop();
            auto [x, y] = cord;
            if (vis[x][y]) continue;
            vis[x][y] = true;
            if (x == n - 1 && y == m - 1) return -mx;
            for (auto [dx, dy] : dir) {
                ll cx = x + dx, cy = y + dy;
                if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
                pq.push({-max(-mx, (ll)grid[cx][cy]), {cx, cy}});
            }
        }
        return -1;
    }
};