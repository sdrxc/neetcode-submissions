class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if(n==0 || n==1)
        return 0;

        /*
        option 1 = minimum cost till n-1  + cost[n-1]

        option 2 = minimum cost till n-2 + cost[n-2]

        dp = min(option1, option2)
        */ 

        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;

        for(int i =2;i<=n;i++)
        {
            int option1 = dp[i-1] + cost[i-1];
            int option2 = dp[i-2] + cost[i-2];
            dp[i] = min(option1, option2);
        }

        return dp[n];       
    }
};
