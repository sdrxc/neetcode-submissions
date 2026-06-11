class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;

        for(auto it: nums)
        {
            if(it>0)
            st.insert(it);
        }

        int n = nums.size();

        for(int i=1;i<=n+1;i++)
        {
            if(st.find(i)==st.end())
            {
                return i;
            }
        }

        return n+1;
    }
};