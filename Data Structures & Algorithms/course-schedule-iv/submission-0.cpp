class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // 2D matrix numCourses x numCourses
        vector<vector<bool>> pre(
            numCourses,
            vector<bool>(numCourses, false)
        );

        for (auto &p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            for (int next : graph[curr]) {

                pre[curr][next] = true;

                for (int i = 0; i < numCourses; i++) {
                    if (pre[i][curr])
                        pre[i][next] = true;
                }

                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        vector<bool> ans;

        for (auto &q : queries)
            ans.push_back(pre[q[0]][q[1]]);

        return ans;
    }
};