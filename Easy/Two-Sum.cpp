class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;

        vector<pair<int, int>> indexed_nums;

        for(int k = 0; k < nums.size(); k++)
            indexed_nums.push_back(make_pair(nums[k], k));

        sort(indexed_nums.begin(), indexed_nums.end());

        while(indexed_nums[i].first + indexed_nums[j].first != target)
        {
            if(indexed_nums[i].first + indexed_nums[j].first < target)
                i++;
            else
                j--;
        }

        vector<int> v = {indexed_nums[i].second, indexed_nums[j].second};
        return v;
    }
};