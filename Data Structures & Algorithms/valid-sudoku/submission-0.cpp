class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> boxes(9, 0);

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {

                if(board[r][c] == '.')
                    continue;

                int num = board[r][c] - '0';
                int mask = 1 << num;

                int box = (r / 3) * 3 + (c / 3);

                if((rows[r] & mask) ||
                   (cols[c] & mask) ||
                   (boxes[box] & mask))
                    return false;

                rows[r] |= mask;
                cols[c] |= mask;
                boxes[box] |= mask;
            }
        }

        return true;
    }
};