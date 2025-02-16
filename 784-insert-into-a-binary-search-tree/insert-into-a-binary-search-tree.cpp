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
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        if(root == NULL){
            TreeNode* temp = new TreeNode(data);
            return temp;
        }

        if(root->val > data){
            root->left = insertIntoBST(root->left , data);
        }else{
            root->right = insertIntoBST(root->right , data);
        }
        return root;
    }
};