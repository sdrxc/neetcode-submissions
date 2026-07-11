class Solution {
private:
        vector<vector<int>> ans;
        vector<int> ds;
public:

    void findCombination(int index, int target, vector<int>& nums )
    {

        // terminal case
        if(index == nums.size())
        {
            if(target==0)
            ans.push_back(ds);
            return ;
        }

        // pick up the same element
        if(nums[index]<=target)
        {
            ds.push_back(nums[index]);
            findCombination(index, target-nums[index], nums);
            ds.pop_back();
        }
        
        // skip the element (go forward)
        findCombination(index+1, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        findCombination(0, target, nums);
        return ans;
    }
};
