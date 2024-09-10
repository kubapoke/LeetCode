class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        const int possible_states = 1<<8;

        int used_state_times[possible_states];
        vector<int> states[possible_states];

        for(int i = 0; i < possible_states; i++)
            used_state_times[i] = INT_MIN;

        states[0] = cells;
        used_state_times[state_to_number(cells)] = 0;

        for(int i = 1; i < possible_states; i++)
        {
            vector<int> v(8);

            v[0] = v[7] = 0;
            for(int j = 1; j < 7; j++)
                v[j] = (states[i - 1][j - 1] == states[i - 1][j + 1] ? 1 : 0);

            states[i] = v;
            int state_number = state_to_number(v);

            if(i == n)
                return states[i];

            if(used_state_times[state_number] != INT_MIN)
            {
                int loop_offset = used_state_times[state_number];
                int loop_length = i - used_state_times[state_number];

                int ans_idx = n % loop_length;

                while(ans_idx < loop_offset)
                    ans_idx += loop_length;

                return states[ans_idx];
            }

            used_state_times[state_number] = i;
        }

        vector<int> v;
        return v;
    }

    int state_to_number(vector<int>& v)
    {
        int res = 0, mult = 1;

        for(int i = 0; i < 8; i++)
        {
            res += v[i] * mult;
            mult *= 2;
        }

        return res;
    }
};