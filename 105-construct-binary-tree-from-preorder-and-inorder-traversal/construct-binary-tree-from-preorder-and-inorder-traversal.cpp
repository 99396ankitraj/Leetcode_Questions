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
    TreeNode* solve(vector<int>& preorder ,vector<int>& inorder , int &ind , int s , int e){
        if(s > e) return NULL;

        int i = s;
        for(;i <= e ; i++){
            if(preorder[ind] == inorder[i]) break;
        }
        TreeNode* root = new TreeNode(preorder[ind]);
        ind++;
        root->left = solve(preorder , inorder , ind , s , i-1);
        root->right = solve(preorder , inorder , ind , i+1 , e);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return solve(preorder , inorder , ind , 0 , preorder.size()-1); 
    }
};