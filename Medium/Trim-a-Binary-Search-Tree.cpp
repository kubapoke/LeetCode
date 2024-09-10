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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        recursive_trim(root, low, high);

        return root;
    }

    void recursive_trim(TreeNode*& vertex, int& low, int&high)
    {
        if(vertex == nullptr)
            return;

        while(vertex != nullptr && (vertex->val < low || vertex->val > high))
        {
            if(vertex->val < low)
                vertex = vertex->right;
            else
                vertex = vertex->left;
        }

        if(vertex != nullptr)
        {
            recursive_trim(vertex->left, low, high);
            recursive_trim(vertex->right, low, high);
        }
    }
};