class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //searching in 2d matrix by BS
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = (m*n) -1;

        while(s <= e){
            int mid = s + (e-s)/2;
            int row = mid/n;
            int col = mid%n;
            int midVal = matrix[row][col];

            if(target < midVal){
                e = mid-1;
            } else if(target > midVal){
                s = mid+1;
            } else if(target == midVal){
                return true;
            }
        }
        return false;
    }
};
