class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void dfs(vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(subset);
            return;
        }

        // Take
        subset.push_back(nums[index]);
        dfs(nums, index + 1);

        // Undo
        subset.pop_back();

        // Skip
        dfs(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0);

        return ans;
    }
};