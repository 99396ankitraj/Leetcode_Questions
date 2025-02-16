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
    bool solve(TreeNode* root , long mini , long maxi){
        if(root == NULL) return true;
        
        bool check = root->val > mini && root->val < maxi;
        bool l = solve(root->left , mini , root->val);
        bool r = solve(root->right , root->val , maxi);

        return l&&r&&check;

    }
    bool isValidBST(TreeNode* root) {
        return solve(root , LONG_MIN , LONG_MAX);
    }
};