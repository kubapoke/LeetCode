class Solution {
public:
    string shortestPalindrome(string s) {
        string sr(s);
        reverse(sr.begin(), sr.end());

        string sc = s + '$' + sr;

        int pi[sc.length()];

        pi[0] = 0;
        int j = 0;

        for(int i = 1; i < sc.length(); i++)
        {
            while(j != 0 && sc[i] != s[j])
                j = pi[j - 1];
            if(sc[i] == s[j])
                j++;

            pi[i] = j;
        }

        int to_copy = pi[sc.length() - 1];

        sr += s.substr(to_copy, s.length() - to_copy);

        return sr;
    }
};