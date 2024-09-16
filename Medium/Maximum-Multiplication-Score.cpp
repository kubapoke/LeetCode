class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long max_score = INT_MIN;

        long long dp[4][b.size()];

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                dp[i][j] = INT_MIN;
            }
        }

        dp[0][0] = (long long)a[0] * (long long)b[0];

        for(int j = 1; j < b.size() - 3; j++)
            dp[0][j] = max((long long)a[0] * (long long)b[j], dp[0][j - 1]);

        for(int i = 1; i < 4; i++)
        {
            for(int j = i; j < b.size() - 3 + i; j++)
            {
                dp[i][j] = max((long long)a[i] * (long long)b[j] + dp[i - 1][j - 1], dp[i][j - 1]);
            }
        }

        return dp[3][b.size() - 1];
    }
};