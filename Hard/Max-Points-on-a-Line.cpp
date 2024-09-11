class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;

        for(int i = 0; i < points.size(); i++)
        {
            map<pair<int, int>, int> fracts;

            for(int j = i + 1; j < points.size(); j++)
            {
                fracts[reduce_fraction(points[i][0] - points[j][0], points[i][1] - points[j][1])] += 1;
            }

            for(auto u: fracts)
            {
                if(u.second + 1 > res)
                    res = u.second + 1;
            }
        }

        return res;
    }

    pair<int, int> reduce_fraction(int a, int b)
    {
        if(a == 0)
            return make_pair(INT_MAX, INT_MAX);
        if(b == 0)
            return make_pair(INT_MIN, INT_MIN);

        int x = a < 0 ? -a : a;
        int y = b < 0 ? -b : b;

        if(x < y)
            swap(x, y);

        while(y)
        {
            int t = y;
            y = x % y;
            x = t;
        }

        a /= x;
        b /= x;

        if(b < 0)
        {
            a *= -1;
            b *= -1;
        }

        return make_pair(a, b);
    }
};