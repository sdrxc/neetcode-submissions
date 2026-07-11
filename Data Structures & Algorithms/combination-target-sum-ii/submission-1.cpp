class Solution {
private:
    vector<vector<int>> ans;
    vector<int> ds;

public:

    void findCombination(int index, int target, vector<int>& nums)
    {
        // Found a valid combination
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            // Skip duplicates
            if(i > index && nums[i] == nums[i-1])
                continue;

            // Since array is sorted
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