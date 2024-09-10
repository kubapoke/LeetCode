class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, score;

        if(s.length() == 0)
            return res;

        stack<int> S;
        int scores[s.length()];

        for(int i = 0; i < s.length(); i++)
        {
            scores[i] = 0;

            if(s[i] == '(')
            {
                S.push(i);
            }
            else if(!S.empty())
            {
                int top = S.top();
                S.pop();

                score = i - top + 1;
                if(top != 0)
                    score += scores[top - 1];

                scores[i] = score;
                res = max(res, score);
            }
        }

        return res;
    }
};