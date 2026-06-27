class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;
        int n=nums2.size();
        stack<int> st;

        for(int i =n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            st.pop();

            if(!st.empty())
            um[nums2[i]] = st.top();
            else
            um[nums2[i]] = -1;

            st.push(nums2[i]);
        }

        vector<int> res;

        for(auto it: nums1)
        res.push_back(um[it]);

        return res;

    }
};