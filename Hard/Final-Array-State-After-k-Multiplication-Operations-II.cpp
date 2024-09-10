class Solution {
public:
    struct comp{
        template<typename T>
        bool operator()(T const& lhs, T const& rhs) const {
            return lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first > rhs.first;
        }
    };

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1)
            return nums;

        const int mod = 1e9 + 7, n = nums.size();
        int init_max = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, comp> PQ;

        for(int i = 0; i < nums.size(); i++)
        {
            PQ.push(make_pair(nums[i], i));

            if(nums[i] > init_max)
                init_max = nums[i];
        }

        vector<long long> v(begin(nums), end(nums));

        while(k > 0)
        {
            pair<long long, int> p = PQ.top();

            if(p.first * multiplier > init_max)
                break;

            PQ.pop();

            int idx = p.second;
            v[idx] *= multiplier;

            PQ.push(make_pair(v[idx], idx));

            k--;
        }

        int mults_left = k / n;
        int additional_mults = k % n;

        long long power = quick_pow_mod(multiplier, mults_left, mod);


        while(PQ.size())
        {
            pair<long long, int> p = PQ.top();
            PQ.pop();

            int idx = p.second;

            v[idx] = (v[idx] * power) % mod;

            if(additional_mults)
            {
                v[idx] = (v[idx] * multiplier) % mod;
                additional_mults--;
            }
        }

        vector<int> ret(begin(v), end(v));

        return ret;
    }

    long long quick_pow_mod(int a, int b, int mod)
    {
        static const int N = 40;
        long long pows[N];
        long long res = 1;
        int i = 0;

        pows[0] = a % mod;

        for(int i = 1; i < N; i++)
        {
            pows[i] = (pows[i - 1] * pows[i - 1]) % mod;
        }

        while(b > 0)
        {
            if(b % 2)
            {
                res = (res * pows[i]) % mod;
            }

            b/=2;
            i++;
        }

        return res;
    }
};