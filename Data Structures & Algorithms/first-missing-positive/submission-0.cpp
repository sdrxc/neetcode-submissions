class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<=n+1;i++)
        {
            auto it = find(nums.begin(), nums.end(), i);
            if(it==nums.end())
            {
                return i;
            }
        }

        return 0;
    }
};