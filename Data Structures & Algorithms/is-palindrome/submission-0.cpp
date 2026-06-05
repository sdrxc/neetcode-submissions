class Solution {
public:
    bool isPalindrome(string s) {

        string res;

        for (char ch : s) {
            if (isalnum(ch)) {
                res.push_back(tolower(ch));
            }
        }

        int left = 0;
        int right = res.size() - 1;

        while (left < right) {
            if (res[left] != res[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};