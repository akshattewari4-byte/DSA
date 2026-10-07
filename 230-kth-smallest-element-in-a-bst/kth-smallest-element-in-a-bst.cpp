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
    int prevo = 0;

    int kth(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        // Left
        if (root->left) {
            int lef = kth(root->left, k);

            if (lef != -1) {
                return lef;
            }
        }

        // Current node
        prevo++;

        if (prevo == k) {
            return root->val;
        }

        // Right
        if (root->right) {
            int rig = kth(root->right, k);

            if (rig != -1) {
                return rig;
            }
        }

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        return kth(root, k);
    }
};