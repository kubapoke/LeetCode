class Solution {
public:
    bool isNumber(string s) {
        set<char> allowed_chars({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '+', '-'});
        bool contains_digit = false, contains_digit_post_e = true;

        for(int i = 0; i < s.size(); i++)
        {
            if(!allowed_chars.contains(s[i]))
                return false;

            if(i == 0 || (i != 0 && (s[i - 1] == 'e' || s[i - 1] == 'E')));
            {
                allowed_chars.erase('+');
                allowed_chars.erase('-');
            }

            if(s[i] == 'e' || s[i] == 'E')
            {
                contains_digit_post_e = false;
                allowed_chars.insert('+');
                allowed_chars.insert('-');
                allowed_chars.erase('.');
                allowed_chars.erase('e');
                allowed_chars.erase('E');
            }

            if(s[i] == '.')
            {
                allowed_chars.erase('.');
            }

            if(s[i] >= '0' && s[i] <= '9' && !contains_digit)
            {
                contains_digit = true;
                allowed_chars.insert('e');
                allowed_chars.insert('E');
            }

            if(s[i] >= '0' && s[i] <= '9' && !contains_digit_post_e)
            {
                contains_digit_post_e = true;
            }
        }

        return contains_digit && contains_digit_post_e;
    }
};