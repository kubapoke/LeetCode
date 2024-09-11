class Solution {
public:
    string reverseVowels(string s) {
        int b = 0, e = s.size() - 1;

        while(b < e)
        {
            while(s[b] != 'a' && s[b] != 'e' && s[b] != 'i' && s[b] != 'o' && s[b] != 'u' && s[b] != 'A' && s[b] != 'E' && s[b] != 'I' && s[b] != 'O' && s[b] != 'U')
            {
                b++;

                if(b >= e)
                    return s;
            }
            while(s[e] != 'a' && s[e] != 'e' && s[e] != 'i' && s[e] != 'o' && s[e] != 'u' && s[e] != 'A' && s[e] != 'E' && s[e] != 'I' && s[e] != 'O' && s[e] != 'U')
            {
                e--;

                if(e <= b)
                    return s;
            }

            swap(s[b], s[e]);
            b++; e--;
        }

        return s;
    }
};