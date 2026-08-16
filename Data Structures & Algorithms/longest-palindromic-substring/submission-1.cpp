class Solution {
private:
    // Expands outward from indices left and right
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length of valid palindrome found
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindrome (e.g., "aba" centered at 'b')
            int len1 = expandFromCenter(s, i, i);
            
            // Case 2: Even length palindrome (e.g., "abba" centered between 'b' and 'b')
            int len2 = expandFromCenter(s, i, i + 1);

            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                // Calculate starting index of the new longest palindrome
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};