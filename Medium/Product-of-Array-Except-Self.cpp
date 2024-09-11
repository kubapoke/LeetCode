class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_mult(n);
        vector<int> suffix_mult(n);
        vector<int> mult(n);

        prefix_mult[0] = nums[0];
        suffix_mult[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++)
        {
            prefix_mult[i] = nums[i] * prefix_mult[i - 1];
            suffix_mult[n - 1 - i] = nums[n - 1 - i] * suffix_mult[n - i];
        }

        mult[0] = suffix_mult[1];
        mult[n - 1] = prefix_mult[n - 2];

        for(int i = 1; i < n - 1; i++)
        {
            mult[i] = prefix_mult[i - 1] * suffix_mult[i + 1];
        }

        return mult;
    }
};