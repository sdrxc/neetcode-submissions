class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> um;

        // um[0] = 1;
        for(int i =0;i<nums.size();i++)
        {
            int rem = target - nums[i];
            if(um.find(rem)!=um.end())
            {
                return {um[rem],i};
            }
            um[nums[i]] = i;
        }

        return {-1,-1};
    }
};
