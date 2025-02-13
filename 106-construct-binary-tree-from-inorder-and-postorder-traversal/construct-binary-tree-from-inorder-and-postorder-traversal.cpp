class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int &ind , int s , int e){
        if(s > e) return NULL;
        
        // Find the root value from postorder traversal
        int rootVal = postorder[ind];
        TreeNode* root = new TreeNode(rootVal);
        
        // Move index to the previous node in postorder traversal
        ind--;
        
        // Find the root in the inorder traversal
        int i = s;
        for(; i <= e ; i++){
            if(inorder[i] == rootVal) break;
        }

        // Recursively build the right subtree (since postorder is left-right-root)
        root->right = solve(inorder , postorder , ind , i + 1 , e);
        
        // Recursively build the left subtree
        root->left = solve(inorder , postorder , ind , s , i - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = postorder.size() - 1;
        return solve(inorder , postorder , ind , 0 , inorder.size() - 1);
    }
};
