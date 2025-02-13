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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int &ind , int s , int e){
        if(s > e) return NULL;
        int i = s;

        for(; i < e ; i++){
            if(postorder[ind] == inorder[i]) break;
        }

        TreeNode* root = new TreeNode(postorder[ind]);
        ind--;
        root->right = solve(inorder , postorder , ind , i+1 , e);
        root->left = solve(inorder , postorder , ind , s , i-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = inorder.size()-1;
        return solve(inorder , postorder , ind , 0 , postorder.size()-1);
    }
};