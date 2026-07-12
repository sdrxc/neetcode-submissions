class Solution {
private:
    vector<vector<int>> res;
    vector<int> ds;

    void findCombination(int index, int target, vector<int>& candidates)
    {
        if (target == 0)
        {
            res.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);
            findCombination(i + 1, target - candidates[i], candidates);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        findCombination(0, target, candidates);
        return res;
    }
};