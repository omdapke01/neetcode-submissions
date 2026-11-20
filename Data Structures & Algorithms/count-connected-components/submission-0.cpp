class Solution {
    private:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int s){
        vis[s] = true;

        for(int i : adj[s]){
            if(!vis[i]){
                dfs(adj, vis, i);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                cnt++;
            }
        }
        return cnt;
    }
};
