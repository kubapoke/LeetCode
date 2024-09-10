class Solution {
public:
    int countDigitOne(int n) {
        int i = 0, res = 0, remainder = 0, digit;
        long long pow = 1;

        while(n > 0)
        {
            res += (n / 10) * pow;
            if(n % 10 != 0)
                res += pow;

            digit = n % 10;

            if(digit == 1)
            {
                res = res - pow + remainder + 1;
            }

            n /= 10;
            remainder = remainder + pow * digit;
            pow *= 10;
        }

        return res;
    }
};