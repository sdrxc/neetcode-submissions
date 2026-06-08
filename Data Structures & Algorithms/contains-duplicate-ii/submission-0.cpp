class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if(um.count(num) && abs(i-um[num])<=k)
            {
                return true;
            }
            um[num] = i;
        }

        return false;
    }
};