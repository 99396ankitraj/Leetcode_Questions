/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr)) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if (root == nullptr) return -1;

        // Search in the left subtree
        int left = kthSmallest(root->left, k);
        if (left != -1) return left;

        // Process the current node
        k--;
        if (k == 0) return root->val;

        // Search in the right subtree
        return kthSmallest(root->right, k);
    }
};
