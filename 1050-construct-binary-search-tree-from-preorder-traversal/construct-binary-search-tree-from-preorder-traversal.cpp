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
   TreeNode* solve(TreeNode* root , int data){
      if(root == NULL){
         return new TreeNode(data);
      }
      if(root->val > data){
        root->left = solve(root->left , data);
      }else{
        root->right = solve(root->right , data);
      }
      return root;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = NULL;
        for(int i = 0 ; i < n ; i++){
            root = solve(root , preorder[i]);
        }
        return root;
    }
};