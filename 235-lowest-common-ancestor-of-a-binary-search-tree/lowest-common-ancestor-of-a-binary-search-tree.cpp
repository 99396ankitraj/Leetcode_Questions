/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(p->val > q->val) return lowestCommonAncestor(root,q,p);
         
         //if(root == NULL) return NULL;

         if(root->val >= p->val && q->val >= root->val) return root;
         
         if(root->val > p->val){
           return lowestCommonAncestor(root->left , p , q);
         }else{
           return lowestCommonAncestor(root->right , p , q);
         }
    }
};