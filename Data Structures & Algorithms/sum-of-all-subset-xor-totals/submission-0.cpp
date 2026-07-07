class Solution {
private:
int ans =0;
public:
    void dfs(vector<int>& nums, int idx, int currXor)
    {
        if (idx == nums.size()) {
            ans += currXor;
            return;
        }
        // Include current element
        dfs(nums, idx + 1, currXor ^ nums[idx]);

        // Exclude current element
        dfs(nums, idx + 1, currXor);


    }

    int subsetXORSum(vector<int>& nums) {
        dfs(nums,0,0);
        return ans;
    }
};