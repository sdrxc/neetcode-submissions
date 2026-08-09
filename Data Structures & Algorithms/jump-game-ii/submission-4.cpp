class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int jumps=0;

        while(!q.empty())
        {
            int size =q.size();

            while(size--)
            {
                int i = q.front();
                q.pop();

                if(i == n-1)
                return jumps;

                for(int step =1;step <=nums[i];step++)
                {
                 int next = i + step;

                if(next < n && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }                   
                }
            }
           jumps++; // moving to next level

        }
    return -1;

    }
};
