class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())
        return 0;

        sort(nums.begin(), nums.end());

        int max_len = 1;
        int local_len =1;
        for(int i=1;i<nums.size();i++)
        {

            if (nums[i] == nums[i - 1])
                continue;

            if(nums[i]==nums[i-1]+1)
            {
                local_len++;
            }
            else
            {
                local_len = 1;
            }
            
            max_len = max(max_len, local_len);

        }

        return max_len;
    }
};