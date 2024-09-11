class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int rem = 0, i = 0;
        int max_len = max(num1.size(), num2.size());

        while(i < max_len || rem != 0)
        {
            int dig1 = (i < num1.size() ? num1[num1.size() - i - 1] - '0' : 0);
            int dig2 = (i < num2.size() ? num2[num2.size() - i - 1] - '0' : 0);
            int dig = dig1 + dig2 + rem;

            i++;
            rem = 0;
            if(dig >= 10)
            {
                rem = 1;
                dig -= 10;
            }

            sum = (char)('0' + dig) + sum;
        }

        return sum;
    }
};