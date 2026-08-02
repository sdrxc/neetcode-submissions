class Solution {
   private:
    int rows, cols;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c] = true;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

            if (visited[nr][nc]) continue;

            if (heights[nr][nc] < heights[r][c]) continue;

            // backward contion heights[nr][nc] >= heights[r][c])
            dfs(heights, nr, nc, visited);
        }
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific
        // top row
        for (int c = 0; c < cols; c++) dfs(heights, 0, c, pacific);

        // lefmost col
        for (int r = 0; r < rows; r++) dfs(heights, r, 0, pacific);

        // atlantic
        // bottom row
        for (int c = 0; c < cols; c++) dfs(heights, rows - 1, c, atlantic);

        // rightmost col
        for (int r = 0; r < rows; r++) dfs(heights, r, cols - 1, atlantic);

        vector<vector<int>> ans;

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }

        return ans;
    }
};