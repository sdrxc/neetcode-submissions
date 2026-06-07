class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> box(9);

        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                char ch = board[r][c];
                if(ch== '.')
                continue;

                int box_id = (r/3)*3 + (c/3);
              
                if(row[r].count(ch) || col[c].count(ch)|| box[box_id].count(ch))
                return false;

                row[r].insert(ch);
                col[c].insert(ch);
                box[box_id].insert(ch);

            }
        }

        return true;

    }
};
