/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = INT_MIN;

    int maxPathSum(TreeNode* root) {
        recursive_sum(root);
        return res;
    }

    int recursive_sum(TreeNode* v)
    {
        if(v == nullptr)
            return 0;

        int left_best_path = recursive_sum(v->left);
        int right_best_path = recursive_sum(v->right);

        int down_path_max = max(v->val, v->val + max(left_best_path, right_best_path));
        res = max(res, down_path_max);

        int split_path_max = v->val + left_best_path + right_best_path;
        res = max(res, split_path_max);

        return down_path_max;
    }
};