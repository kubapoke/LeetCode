class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26);
        int res = 0;

        for(auto c: chars)
        {
            counts[c - 'a']++;
        }

        for(auto word: words)
            res += added_value(word, counts);

        return res;
    }

    int added_value(string s, vector<int> counts)
    {
        for(auto c: s)
        {
            if(counts[c - 'a'] <= 0)
                return 0;
            counts[c - 'a']--;
        }

        return s.size();
    }
};