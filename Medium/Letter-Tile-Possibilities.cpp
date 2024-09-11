class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> counts(26);

        for(auto l: tiles)
        {
            counts[l - 'A']++;
        }

        queue<char> usable_chars;

        for(int i = 0; i < 26; i++)
            if(counts[i])
                usable_chars.push(i + 'A');

        return recursive_count(counts, usable_chars) - 1;
    }

    int recursive_count(vector<int>& counts, queue<char>& chars)
    {
        if(chars.size() == 0)
            return 1;

        int res = 1;

        int n = chars.size();

        for(int i = 0; i < n; i++)
        {
            char c = chars.front();
            chars.pop();

            counts[c - 'A']--;

            if(counts[c - 'A'])
                chars.push(c);

            res += recursive_count(counts, chars);

            if(!counts[c - 'A'])
                chars.push(c);

            counts[c - 'A']++;
        }

        return res;
    }
};