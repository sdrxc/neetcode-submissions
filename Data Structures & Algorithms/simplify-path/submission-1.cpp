class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> st_vec;
        string curr="";

        stringstream ss(path);

        while(getline(ss, curr, '/'))
        {
            if(curr=="" || curr==".")
            {
                continue;
            }
            else if(curr=="..")
            {
                if(!st_vec.empty())
                st_vec.pop_back();
            }
            else
            {
                st_vec.push_back(curr);
            }
        }

        string ans="";

        for(auto it:st_vec)
        {
            ans+="/"+it;
        }

        return ans.empty() ? "/" : ans;
    }
};