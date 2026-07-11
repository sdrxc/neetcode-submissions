class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(vector<int>& nums, int start)
    {
        ans.push_back(subset);

        for(int i=start;i < nums.size();i++)
        {
            subset.push_back(nums[i]);
            dfs(nums, i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0);
        return ans;
    }
};


// [1,2]
// dfs(0) subset=[]

// ├── Take 1
// │   dfs(1) subset=[1]
// │
// │   ├── Take 2
// │   │   dfs(2) subset=[1,2]
// │   │   -> store [1,2]
// │   │
// │   └── Skip 2
// │       dfs(2) subset=[1]
// │       -> store [1]
// │
// └── Skip 1
//     dfs(1) subset=[]
    
//     ├── Take 2
//     │   dfs(2) subset=[2]
//     │   -> store [2]
//     │
//     └── Skip 2
//         dfs(2) subset=[]
//         -> store []