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
    bool solve(TreeNode* root , int k , unordered_set<int> &st){
        if(root == NULL) return false;

        if(st.find(root->val) != st.end()) return true;
        st.insert(k - root->val);

        if(solve(root->left , k , st)) return true;
        if(solve(root->right , k , st)) return true;

        return false;

    }
    bool findTarget(TreeNode* root, int k) {
        if(root->left == NULL && root->right == NULL) return false;
        unordered_set<int> st;
        return solve(root , k , st);
    }
};