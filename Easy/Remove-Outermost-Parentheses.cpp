class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> S; // denotes parentheses openings
        vector<pair<int, int>> V; // denotes outermost parentheses

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                S.push(i);
            else
            {
                if(S.size() == 1)
                    V.push_back(make_pair(S.top() + 1, i - S.top() - 1));
                S.pop();
            }
        }

        string res = "";

        for(auto u: V)
        {
            res += s.substr(u.first, u.second);
        }

        return res;
    }
};