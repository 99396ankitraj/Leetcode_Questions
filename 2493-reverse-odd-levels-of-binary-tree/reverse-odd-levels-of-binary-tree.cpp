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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            vector<TreeNode*> arr;
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop();
                arr.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(level % 2 != 0){
                int i = 0;
                int j = arr.size()-1;

                while(i < j){
                    int temp = arr[i]->val;
                    arr[i]->val = arr[j]->val;
                    arr[j]->val = temp;
                    i++;
                    j--;
                }
            }
            level++;

        }

        return root;
    }
};