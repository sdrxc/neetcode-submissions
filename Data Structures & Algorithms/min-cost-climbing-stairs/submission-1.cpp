class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0; // Cost to reach step i-2
        int prev1 = 0; // Cost to reach step i-1

        for (int c : cost) {
            int current = c + min(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }

        // To reach top of floor, take min of reaching last two steps
        return min(prev1, prev2);
    }
};