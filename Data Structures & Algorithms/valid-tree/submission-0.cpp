class Solution {
    private:
    bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>>& adj, int &cnt){
        
        vis[node] = 1;
        cnt++;

        for(int neigh : adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh, node, vis, adj, cnt)){
                    return true;
                }
            } else if(neigh != parent) return true;
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
//a tree is a undirected graph with no cycles
//basically write an algo to detect a cycle in undirected graph
    if(edges.size() != n-1) return false;

    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);
    for(auto &it : edges){
        int u = it[0];
        int v = it[1];

        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int cnt = 0;
    if(dfs(0, -1, vis, adj, cnt)) return false;

    return cnt == n;
    }
};
