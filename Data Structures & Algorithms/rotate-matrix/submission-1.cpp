class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        // step 1: Transpose the matrix
        // step 2: Reverse the rows

        int m = matrix.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
