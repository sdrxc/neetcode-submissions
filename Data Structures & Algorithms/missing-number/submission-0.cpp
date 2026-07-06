class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto it: nums)
        um[it]++;
        int n = nums.size();
        for(int i=0;i<=n;i++)
        {
            if(!um[i])
            return i;
        }

        return -1;
    }
};
