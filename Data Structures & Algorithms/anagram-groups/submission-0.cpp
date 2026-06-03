class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> um;

    for(auto it: strs)
    {
        string key = it;
        sort(key.begin(),key.end());
        um[key].push_back(it);
    }

    vector<vector<string>> res; 
    for(auto it: um)
    {
        res.push_back(it.second);
    }

    return res;

           
    }
};
