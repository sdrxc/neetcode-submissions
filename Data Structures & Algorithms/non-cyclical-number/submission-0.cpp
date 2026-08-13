class Solution {
    // Helper function to calculate the sum of the squares of digits
    int sumOfSquares(int num) {
        int total = 0;
        while (num > 0) {
            int digit = num % 10;
            total += digit * digit;
            num /= 10;
        }
        return total;
    }

   public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = sumOfSquares(n);
        }
        
        return n==1;
    }
};
