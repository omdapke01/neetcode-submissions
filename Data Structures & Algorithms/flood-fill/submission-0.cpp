class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int oldColor = image[sr][sc];

        if(oldColor == color) return image;

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        queue<pair<int, int>> q;
        image[sr][sc] = color;

        q.push({sr, sc});

        while(!q.empty()){
            pair<int, int> cell = q.front();
            q.pop();

            for(int i = 0; i<4; i++){
                int newRow = cell.first + delrow[i];
                int newCol = cell.second + delcol[i];

                if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && image[newRow][newCol] == oldColor){
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};