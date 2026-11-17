class Solution {
    private:
    int bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();
        int area = 1;
        // 4 directions
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = curRow + delrow[i];
                int ncol = curCol + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1 &&
                   !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    area++;
                }
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        int maxArea = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(!vis[row][col] && grid[row][col] == 1) {
                    
                    int currArea = bfs(row, col, vis, grid);
                    maxArea = max(currArea, maxArea);
                }
            }
        }

        return maxArea;
    }
};
