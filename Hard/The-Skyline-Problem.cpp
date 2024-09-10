class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> V;
        multiset<int> MS;

        for(auto building: buildings)
        {
            V.push_back(make_pair(building[0], building[2]));
            V.push_back(make_pair(building[1], -building[2]));
        }

        sort(V.begin(), V.end());

        int old_height = 0, new_height;

        for(int i = 0; i < V.size(); )
        {
            int position = V[i].first;

            while(i < V.size() && V[i].first == position)
            {
                int height = V[i].second;

                if(height > 0)
                {
                    MS.insert(height);
                }
                else
                {
                    MS.erase(MS.lower_bound(-height));
                }

                i++;
            }

            new_height = (MS.size() > 0 ? *MS.rbegin() : 0);

            if(new_height != old_height)
            {
                vector v = {position, new_height};
                res.push_back(v);
                old_height = new_height;
            }
        }

        return res;
    }
};