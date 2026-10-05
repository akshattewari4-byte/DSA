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
    bool help(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) {
            return true;
        }

        // root should be greater than min
        if (min != NULL && root->val <= min->val) {
            return false;
        }

        // root should be smaller than max
        if (max != NULL && root->val >= max->val) {
            return false;
        }

        return help(root->left, min, root) &&
               help(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return help(root, NULL, NULL);
    }
};