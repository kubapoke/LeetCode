class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[k + 1][prices.size()];
        int res = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= k; i++)
        {
            int max_start_value = INT_MIN;

            for(int j = i - 1; j < prices.size(); j++)
            {
                if(j == 0)
                {
                    max_start_value = max(max_start_value, -prices[j]);
                }
                else
                {
                    max_start_value = max(max_start_value, dp[i - 1][j - 1] - prices[j]);
                }

                dp[i][j] = j == i - 1 ? max_start_value + prices[j] : max(dp[i][j - 1], max_start_value + prices[j]);
            }

            res = max(res, dp[i][prices.size() - 1]);
        }

        return res;
    }
};