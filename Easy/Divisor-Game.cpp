class Solution {
public:
    bool divisorGame(int n) {
        bool can_win[n + 2];

        for(int i = 0; i <= n; i++)
            can_win[i] = false;

        can_win[0] = can_win[2] = true;

        for(int i = 3; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                if(i % j == 0)
                {
                    int rev = i / j;

                    if(can_win[i - j] == false || can_win[i - rev] == false)
                        can_win[i] = true;
                }
            }
        }

        return can_win[n];
    }
};