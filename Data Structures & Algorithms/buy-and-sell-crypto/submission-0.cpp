class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_pric = INT_MAX;
        int max_pro = 0;

        for(int i=1;i<prices.size();i++)
        {
            min_pric = min(min_pric, prices[i-1]);
            max_pro = max(max_pro, (prices[i]-min_pric));
        }

        return max_pro;
    }
};
