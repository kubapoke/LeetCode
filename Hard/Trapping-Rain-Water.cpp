class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size());
        vector<int> max_right(height.size());

        max_left[0] = height[0];
        max_right[height.size() - 1] = height[height.size() - 1];

        for(int i = 1, j = height.size() - 2; i < height.size(); i++, j--)
        {
            max_left[i] = max(max_left[i - 1], height[i]);
            max_right[j] = max(max_right[j + 1], height[j]);
        }

        int res = 0;

        for(int i = 0; i < height.size(); i++)
        {
            res += min(max_left[i], max_right[i]) - height[i];
        }

        return res;
    }
};