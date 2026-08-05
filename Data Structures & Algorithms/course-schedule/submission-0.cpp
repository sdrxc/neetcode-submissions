class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // forming the graph and storing indegree
        for(auto prerequisite: prerequisites)
        {
            int u = prerequisite[0];
            int v = prerequisite[1];

            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i =0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        int completed=0;

        while(!q.empty())
        {
            int curr =q.front();
            q.pop();

            completed++;

            for(auto neigh: graph[curr])
            {
                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }


       return completed ==  numCourses;
    }
};
