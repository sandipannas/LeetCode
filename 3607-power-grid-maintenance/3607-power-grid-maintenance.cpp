using pii = pair<int,int>;

class Solution {
public:
    vector<vector<int>> graph;                  
    vector<int> stationToGrid;                     
    vector<set<pii>> powerGrids;                  
    vector<bool> visited;                          
    
    void dfs(int station, set<pii>& gridSet, int gridId) {
        visited[station] = true;
        stationToGrid[station] = gridId;
        gridSet.insert({1, station}); 
        
        for (int neighbor : graph[station]) {
            if (!visited[neighbor])
                dfs(neighbor, gridSet, gridId);
        }
    }
    
    vector<int> processQueries(
        int c, vector<vector<int>>& connections, vector<vector<int>>& queries) 
    {
        graph.assign(c + 1, {});
        visited.assign(c + 1, false);
        stationToGrid.resize(c + 1);
        
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int gridId = 0;
        for (int s = 1; s <= c; ++s) {
            if (!visited[s]) {
                set<pii> gridSet;
                dfs(s, gridSet, gridId);
                powerGrids.push_back(gridSet);
                gridId++;
            }
        }
        
        vector<int> result;
        
        for (auto& q : queries) {
            int type = q[0], station = q[1];
            int gridId = stationToGrid[station];
            
            if (type == 1) {
                if (powerGrids[gridId].count({1, station})) {
                    result.push_back(station);
                } else {
                    auto it = powerGrids[gridId].begin();
                    if (it->first == 1) 
                        result.push_back(it->second);
                    else 
                        result.push_back(-1);
                }
            } 
            else if (type == 2) {
                if (powerGrids[gridId].count({1, station})) {
                    powerGrids[gridId].erase({1, station});
                    powerGrids[gridId].insert({2, station});
                }
            }
        }
        
        return result;
    }
};