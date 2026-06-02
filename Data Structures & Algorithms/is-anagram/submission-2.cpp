class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> um;

        for (auto it : s)
        um[it]++;

        for(auto it: t)
        {
            if(um.find(it)==um.end() || um[it]==0)
            return false;

            um[it]--;
        }

        return true;
    }
};
