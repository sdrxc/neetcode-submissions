class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<int,int> um_s;
        unordered_map<int,int> um_t;

        for(auto it: s)
        um_s[it]++;
        
        for(auto it: t)
        um_t[it]++;    

        for( auto it: s)
        {
            if(um_s[it]!=um_t[it])
            return false;
        }

        for( auto it: t)
        {
            if(um_s[it]!=um_t[it])
            return false;
        }

        return true;
    }
};
