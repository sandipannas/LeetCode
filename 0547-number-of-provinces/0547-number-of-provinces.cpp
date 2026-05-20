class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find_parent(int node){
        //cout<<"finding the parent of "<<node<<endl;
        if(node==parent[node]){
            return node;
        }

        //path compession
        return parent[node]=find_parent(parent[node]);

    }

    void union_rank(int u,int v){
        if(rank[parent[u]]<rank[parent[v]]){
            parent[parent[u]]=parent[v];
        }
        else if(rank[parent[u]]>rank[parent[v]]){
            parent[parent[v]]=parent[u];
        }
        else{
            rank[parent[u]]++;
            parent[parent[v]]=parent[u];
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        parent.resize(isConnected.size());
        rank.resize(isConnected.size(),1);
        int count=isConnected.size();

        for(int i=0;i<isConnected.size();i++){ parent[i]=i; }

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                
                if(i==j || isConnected[i][j]==0){ continue; }

                int parent_u=find_parent(i);
                int parent_v=find_parent(j);

                if(parent_u!=parent_v){ count--; union_rank(i,j); }
            }
        }
        return count;
    }
};