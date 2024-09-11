class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int sum = 0;

        int i = bits.size() - 2;

        while(i >= 0 && bits[i] == 1)
        {
            sum++;
            i--;
        }

        return sum % 2 == 0;
    }
};