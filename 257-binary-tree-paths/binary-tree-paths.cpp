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
    void solve(TreeNode* root , vector<string>&ans , string str){
        if(root == NULL) return;

        str += to_string(root->val) + "->";
        if(root->left == NULL && root->right == NULL){
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
            return;
        }
        solve(root->left , ans , str);
        solve(root->right , ans , str);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root , ans , "");
        return ans;
    }
};