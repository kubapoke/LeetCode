class Solution {
public:
    string customSortString(string order, string s) {
        string ret = "";
        int counts[26];

        for(int i = 0; i < 26; i++)
            counts[i] = 0;

        for(auto l: s)
        {
            counts[l - 'a']++;
        }

        for(int i = 0; i < order.size(); i++)
        {
            char l = order[i];

            ret += string(counts[l - 'a'], l);
            counts[l - 'a'] = 0;
        }

        for(int i = 0; i < 26; i++)
        {
            ret += string(counts[i], i + 'a');
        }

        return ret;
    }
};