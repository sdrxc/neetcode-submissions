class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
        sort(strs.begin(),strs.end());
        string first_str = strs[0];
        int n = strs.size();
        string last_str = strs[n-1];

        for(int i=0;i<min(first_str.length(), last_str.length());i++)
        {
            if(first_str[i]!=last_str[i])
            return ans;

            ans +=first_str[i];
        }

        return ans;
    }
};