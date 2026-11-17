class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>> & vis, vector<vector<char>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        while(!q.empty()){
            pair<int, int> cell = q.front();
            q.pop();

            for(int i = 0; i<4; i++){
                int newrow = cell.first + delrow[i];
                int newcol = cell.second + delcol[i];

                if(newrow >= 0 && newrow < r && newcol >= 0 && newcol < c && !vis[newrow][newcol] && grid[newrow][newcol] == '1'){
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt = 0;

        for(int row = 0; row<n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
