class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int dp[n][n];
        vector<int> res;

        for(int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }

        for(int offset = 1; offset < n; offset++)
        {
            for(int i = 0, j = offset; j < n; i++, j++)
            {
                dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1];
            }
        }

        for(int offset = 1; offset < n; offset++)
        {
            for(int i = 0, j = offset; j < n; i++, j++)
            {
                int max_prev = max(dp[i + 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], max_prev);
            }
        }

        for(auto q: queries)
        {
            res.push_back(dp[q[0]][q[1]]);
        }

        return res;
    }
};