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
    int getMaxWidth(TreeNode* root) {

        if (root == nullptr)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {

            int current_level = q.size();

            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;

            ans = max(ans, end - start + 1);

            for (int i = 0; i < current_level; i++) {

                TreeNode* curr = q.front().first;
                unsigned long long index = q.front().second;

                q.pop();

                // Normalize index
                //index = index - start;

                if (curr->left) {
                    q.push({curr->left, 2 * index + 1});
                }

                if (curr->right) {
                    q.push({curr->right, 2 * index + 2});
                }
            }
        }

        return ans;
    }

    int widthOfBinaryTree(TreeNode* root) {
        return getMaxWidth(root);
    }
};