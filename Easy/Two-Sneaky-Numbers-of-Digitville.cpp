class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> res(2);
        int i = 0;

        for(auto num: nums)
        {
            if(used[num])
                res[i++] = num;
            used[num] = true;
        }

        return res;
    }
};