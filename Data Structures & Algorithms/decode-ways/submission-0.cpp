class Solution {
   public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev2 = 1;  // Base case: dp[0] = 1 (empty string)
        int prev1 = 1;  // Base case: dp[1] = 1 (first character valid)

        for (int i = 1; i < s.length(); i++) {
            int current = 0;

            // 1-digit check: s[i] must be '1'-'9'
            if (s[i] != '0') {
                current += prev1;
            }
            // 2-digit check: s[i-1...i] must be between "10" and "26"
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
