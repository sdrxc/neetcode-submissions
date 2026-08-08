class Solution {
private: 
    vector<int> parent;
public:

    int find(int x){
        if(parent[x]!=x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if(pa!=pb)
            parent[pa] = pb;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);

        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            unite(u, v);    
        }

        int count= 0;

        for(int i=0;i<n;i++)
        {
            if(find(i)==i)
            {
                count++;
            }
        } 

        return count;  
    }
};
