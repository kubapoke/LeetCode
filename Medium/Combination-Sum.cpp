class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solutions[target + 1];

        vector<int> t;

        solutions[0].push_back(t);


        for(auto candidate: candidates)
        {
            for(int i = candidate; i <= target; i++)
            {
                for(auto prev: solutions[i - candidate])
                {
                    vector<int> v(prev);

                    v.push_back(candidate);

                    solutions[i].push_back(v);
                }
            }
        }

        return solutions[target];
    }
};