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
    vector<int> largestValues(TreeNode* root) {
        queue<pair<TreeNode*, int>> Q;
        int level = 0, level_max = INT_MIN;

        Q.push(make_pair(root, 0));
        vector<int> res;

        if(root == nullptr)
            return res;

        while(Q.size())
        {
            TreeNode* vertex = Q.front().first;
            int curr_level = Q.front().second;
            Q.pop();

            if(curr_level != level)
            {
                res.push_back(level_max);
                level = curr_level;
                level_max = INT_MIN;
            }

            if(vertex->val > level_max)
                level_max = vertex->val;

            if(vertex->left)
            {
                Q.push(make_pair(vertex->left, level + 1));
            }

            if(vertex->right)
            {
                Q.push(make_pair(vertex->right, level + 1));
            }
        }

        res.push_back(level_max);

        return res;
    }
};