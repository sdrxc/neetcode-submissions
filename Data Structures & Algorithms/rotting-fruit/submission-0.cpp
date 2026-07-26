class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // add all rotten eggs
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==2)
                {
                    q.push({r,c});
                }
                else if (grid[r][c] == 1)
                fresh++;
            }
        }

        // no need to continue (zeroth min)
        if (fresh == 0)
            return 0;       
        

        // directions 
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // answer
        int minutes= 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [r,c] = q.front();
                q.pop();

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                     if (nr < 0 || nr >= rows ||
                        nc < 0 || nc >= cols ||
                        grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});                                      
                }
            }

            minutes++;
        }

        if(fresh==0)
        return minutes-1;
        else
        return -1;
    }
};
