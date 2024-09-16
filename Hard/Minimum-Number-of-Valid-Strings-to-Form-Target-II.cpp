class Solution {
public:
    vector<int> get_match(string& target, string& pattern)
    {
        string concat = pattern + '#' + target;
        vector<int> pi(concat.size());

        pi[0] = 0;
        int j = 0;

        for(int i = 1; i < pi.size(); i++)
        {
            while(j > 0 && concat[i] != concat[j])
            {
                j = pi[j - 1];
            }

            if(concat[i] == concat[j])
                j++;

            pi[i] = j;
        }

        vector<int> match(pi.begin() + pattern.size() + 1, pi.end());
        return match;
    }

    int minValidStrings(vector<string>& words, string target) {
        vector<vector<int>> matches;
        vector<int> best_solution(target.size() + 1, 1e9);

        best_solution[0] = 0;

        for(int i = 0; i < words.size(); i++)
            matches.push_back(get_match(target, words[i]));

        for(int i = 0; i < target.size(); i++)
        {
            for(int j = 0; j < matches.size(); j++)
            {
                best_solution[i + 1] = min(best_solution[i + 1], best_solution[i + 1 - matches[j][i]] + 1);
            }
        }

        return best_solution[target.size()] != 1e9 ? best_solution[target.size()] : -1;
    }
};