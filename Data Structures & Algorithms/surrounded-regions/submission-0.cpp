class Solution {
    void safe(int row, int col, vector<vector<char>> &board){
        int rows = board.size();
        int cols = board[0].size();

        if(row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] != 'O'){
            return;
        }
        //mark curr cell as safe
        board[row][col] = '#';

        safe(row-1, col, board); //up
        safe(row+1, col, board); //down
        safe(row, col-1, board); //left
        safe(row, col+1, board); //right
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int row = 0; row < rows; row++){
            safe(row, 0, board);
            safe(row, cols-1, board);
        }

        for(int col = 0; col < cols; col++){
            safe(0, col, board);
            safe(rows-1, col, board);
        }
        // Flip captured cells and restore safe cells
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(board[row][col] == 'O'){
                    board[row][col] = 'X';
                }
                else if(board[row][col] == '#'){
                    board[row][col] = 'O';
                }
            }
        }
    }
};
