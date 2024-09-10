class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> bits(101);
        int score = 0;
        const int max_bit = 1<<10;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(bits[grid[i][j]].size() == 0 || bits[grid[i][j]][bits[grid[i][j]].size() - 1] != (1<<i))
                    bits[grid[i][j]].push_back(1<<i);
            }
        }

        int dp[101][max_bit];

        for(int i = 0; i < 101; i++)
        {
            for(int j = 0; j < max_bit; j++)
                dp[i][j] = INT_MIN;
        }

        dp[0][0] = 0;

        for(int i = 1; i <= 100; i++)
        {
            for(int j = 0; j < max_bit; j++)
                dp[i][j] = dp[i - 1][j];

            for(auto bit: bits[i])
            {
                for(int j = 0; j < max_bit; j++)
                {
                    if(!(j & bit))
                    {
                        dp[i][j | bit] = max(dp[i][j | bit], dp[i - 1][j] + i);
                        score = max(score, dp[i][j | bit]);
                    }
                }
            }
        }

        return score;
    }
};