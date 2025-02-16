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
    int minval(TreeNode* root){
        if(root->left== NULL && root->right==NULL) return root->val;
        if(!root->left && root->right) return root->val;

        return minval(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
           if(root == NULL) return NULL;

           if(root->val == key){
              //no child
              if(root->left == NULL && root->right == NULL){
                 delete root;
                 return NULL;
              }else if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
              }else if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
              }else{
                 //it node has 2 child
                 int min = minval(root->right);
                 root->val = min;
                 root->right =  deleteNode(root->right , min);
              }
           }else if(root->val > key){
               root->left = deleteNode(root->left , key);
           }else{
               root->right = deleteNode(root->right , key);
           }

           return root;
    }
};