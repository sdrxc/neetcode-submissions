class Solution {
private:
    vector<vector<int>> ans;
    vector<int> ds;

public:
    void findCombination(int start, int target, vector<int>& nums)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i = start; i < nums.size(); i++)
        {
            // Skip duplicates
            if(i > start && nums[i] == nums[i - 1])
                continue;

            if(nums[i] > target)
                break;

            ds.push_back(nums[i]);

            // Move to next index (cannot reuse)
            findCombination(i + 1, target - nums[i], nums);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        findCombination(0, target, nums);

        return ans;
    }
};