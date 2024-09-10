class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n, j;

        for(int i = 0; i < nums.size(); i++)
        {
            n = nums[i];

            while(n >= 1 && n <= nums.size() && nums[n - 1] != n)
            {
                swap(nums[n - 1], nums[i]);

                n = nums[i];
            }
        }

        int res = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == i + 1)
                res++;
            else
                break;
        }

        return res;
    }
};