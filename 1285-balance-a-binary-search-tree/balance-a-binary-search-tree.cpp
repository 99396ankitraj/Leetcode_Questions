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
    TreeNode* solve(int s , int e , vector<int>&arr){
        int mid = (s + e)/2;
        if(s > e) return NULL;


        TreeNode* root = new TreeNode(arr[mid]);
        root->left = solve(s , mid-1 , arr);
        root->right = solve(mid+1 , e , arr);
        return root;
    }
    void inorder(TreeNode* root , vector<int>&arr){
        if(root == NULL) return;
        
        inorder(root->left ,arr);
        arr.push_back(root->val);
        inorder(root->right , arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);

        return solve(0 , arr.size()-1 , arr);

    }
};