class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // Step 1: Build graph
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;

        // Step 2: Traverse all nodes
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                components++;  // New component found

                // BFS
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neigh : graph[node]) {
                        if (!visited[neigh]) {
                            visited[neigh] = true;
                            q.push(neigh);
                        }
                    }
                }
            }
        }

        return components;
    }
};