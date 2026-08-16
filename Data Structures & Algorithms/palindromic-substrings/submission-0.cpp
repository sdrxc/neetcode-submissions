class Solution {
   private: 
        int countFromCenter(string s, int left, int right)
        {
            int count =0;

            while(left>=0 && right < s.length() & s[left]==s[right])
            {
                left--;
                right++;
                count++;
            }

            return count;
        }
   public:
    int countSubstrings(string s) {
        int totalPalindromes = 0;
        for (int i = 0; i < s.length(); i++) {
            // 1. Odd length palindromes (centered at character i)
            totalPalindromes += countFromCenter(s, i, i);

            // 2. Even length palindromes (centered between i and i+1)
            totalPalindromes += countFromCenter(s, i, i + 1);
        }

        return totalPalindromes;
    }
};
