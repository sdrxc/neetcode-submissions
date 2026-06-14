class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> position;
        int l = 0;
        int max_len = 0;
        for (int r = 0; r < s.size(); r++) {
            // the element is already present
            if (position.find(s[r]) != position.end() && position[s[r]] >= l) {
                l = position[s[r]] + 1;  // move left pointer just after the last occurrence
            }
            // the element is not present -> add position and update len
            position[s[r]] = r;
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};
