class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        size_t n = digits.size();
        int carry = 1;
        int i = n - 1;

        while (i >= 0) {
            int sum = carry;
            sum = sum + (digits[i] % 10);
            if (sum >= 10)
                carry = 1;
            else
                carry = 0;
            ans.push_back(sum % 10);
            i--;
        }

        if (carry != 0) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
