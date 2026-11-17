class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
//multi source BFS 
        //push all 0s into q as starting point
        for(int r = 0; r<n; r++){
            for(int c = 0; c<m; c++){
                if(grid[r][c] == 0) q.push({r,c});
            }
        }

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
//Multi Source BFS outwards level by level
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 2147483647){
                    //dist is curr cell's dist + 1
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }        
    }
};
