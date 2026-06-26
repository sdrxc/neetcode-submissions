class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        for(auto it: t)
            need[it]++;

        int required = t.size();

        int left=0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right=0;right<s.size();right++)
        {
            if(need[s[right]] >0)
                required--;
            
            need[s[right]]--;

            while(required == 0)
            {
                if(right-left+1 < minLen)
                {
                    minLen = right-left+1;
                    start = left;
                }

                need[s[left]]++;

                if(need[s[left]]>0)
                required++;

                left++;
            }
            
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);


    }
};
