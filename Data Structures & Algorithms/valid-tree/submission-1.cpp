class Solution {
public:

    // void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited)
    // {
    //     visited[node]=true;

    //     for(int neigh: graph[node])
    //     {
    //         if(!visited[neigh])
    //         {
    //             dfs(neigh, graph, visited);
    //         }
    //     }
    // }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size()!=n-1)
        return false;

        vector<vector<int>> graph(n);

        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            // since undirected  u ---- v
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        // BFS
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int neigh: graph[node])
            {
                 if(!visited[neigh])
                 {
                    visited[neigh] = true;
                    q.push(neigh);
                 }
            }
        }

        for( auto v: visited)
        {
            // not visited this node
            if(!v)
            return false;
        }

        return true;
    }
};
