class Solution {
public:
    struct increase_decrease_comp {
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        }
    };

    struct decrease_decrease_comp {
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        }
    };

    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<int> k_point = {coordinates[k][0], coordinates[k][1]};

        sort(coordinates.begin(), coordinates.end(), increase_decrease_comp());

        for(auto u: coordinates)
        {
            cout<<u[0]<<" "<<u[1]<<endl;
        }

        vector<int> lesser, greater;

        for(auto v: coordinates)
        {
            if(v[0] < k_point[0] && v[1] < k_point[1])
                lesser.push_back(v[1]);
            if(v[0] > k_point[0] && v[1] > k_point[1])
                greater.push_back(v[1]);
        }

        return 1 + longest_increasing_subsequence(lesser) + longest_increasing_subsequence(greater);
    }

    int longest_increasing_subsequence(vector<int>& nums) {
        vector<int> lens;

        for(auto u: nums)
        {
            bin_search_modify(u, lens);
        }

        return lens.size();
    }

    void bin_search_modify(int n, vector<int>& v)
    {
        int b = 0, f = v.size(), m;

        while(b < f)
        {
            m = (b + f) / 2;

            if(v[m] < n)
                b = m + 1;
            else
                f = m;
        }

        m = (b + f) / 2;

        if(m == v.size())
            v.push_back(n);
        else
            v[m] = n;
    }
};