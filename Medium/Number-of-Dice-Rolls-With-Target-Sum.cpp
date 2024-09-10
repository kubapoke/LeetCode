class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int dp[n + 1][target + 1]; // dp[a][b] with n dice, how many ways to make sum b
        const int mod = 1e9 + 7;

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= target; j++)
                dp[i][j] = 0;

        dp[0][0] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                if(dp[i][j] > 0)
                {
                    for(int x = j + 1; x <= j + k && x <= target; x++)
                        dp[i + 1][x] = (dp[i + 1][x] + dp[i][j]) % mod;
                }
            }
        }

        return dp[n][target];
    }
};