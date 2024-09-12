class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        int opts = 1 << (num.size() - 1);

        for(int mask = 0; mask < opts; mask++)
        {
            vector<long long> vals;
            long long val = num[0] - '0', pos = 0;
            bool valid = true;

            for(int i = num.size() - 2; i >= 0; i--, pos++)
            {
                if(mask & (1 << i))
                {
                    if(val == 0)
                    {
                        valid = false;
                        break;
                    }
                    val = val * 10 + num[pos + 1] - '0';
                }
                else
                {
                    vals.push_back(val);
                    val = num[pos + 1] - '0';
                }
            }

            if(!valid)
                continue;

            vals.push_back(val);

            vector<string> mult_plus_minus = get_mult_plus_minus(vals, target);

            if(mult_plus_minus.size())
            {
                string placeholder = to_string(vals[0]);
                for(int i = 1; i < vals.size(); i++)
                {
                    placeholder += '+' + to_string(vals[i]);
                }

                for(auto v: mult_plus_minus)
                {
                    int i = 0;
                    for(int j = 0; j < placeholder.length(); j++)
                    {
                        if(placeholder[j] < '0')
                            placeholder[j] = v[i++];
                    }

                    res.push_back(placeholder);
                }
            }
        }

        return res;
    }

    vector<string> get_mult_plus_minus(vector<long long>& nums, int target){
        vector<string> res;
        int opts = 1 << (nums.size() - 1);

        string placeholder(nums.size() - 1, ' ');

        for(int mask = 0; mask < opts; mask++)
        {
            vector<long long> vals;
            long long val = nums[0], pos = 0;

            for(int i = nums.size() - 2; i >= 0; i--, pos++)
            {
                if(mask & (1 << i))
                {
                    placeholder[pos] = '*';
                    val *= nums[pos + 1];
                }
                else
                {
                    vals.push_back(val);
                    placeholder[pos] = '-';
                    val = nums[pos + 1];
                }
            }

            vals.push_back(val);

            vector<string> plus_minus = get_plus_minus(vals, target);

            for(auto v: plus_minus)
            {
                int i = 0;
                for(int j = 0; j < placeholder.length(); j++)
                {
                    if(placeholder[j] != '*')
                        placeholder[j] = v[i++];
                }

                res.push_back(placeholder);
            }
        }

        return res;
    }

    vector<string> get_plus_minus(vector<long long>& nums, int target){
        vector<string> res;
        int opts = 1 << (nums.size() - 1);

        string placeholder(nums.size() - 1, ' ');

        for(int mask = 0; mask < opts; mask++)
        {
            long long val = nums[0], pos = 0;

            for(int i = nums.size() - 2; i >= 0; i--, pos++)
            {
                placeholder[pos] = (1<<i & mask ? '+' : '-');
                val += (1<<i & mask ? nums[pos + 1] : -nums[pos + 1]);
            }

            if(val == target)
                res.push_back(placeholder);
        }

        return res;
    }
};