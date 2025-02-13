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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* temp = NULL;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->val == start){
                temp = node;
            }
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }

        //now we will perform bfs
        int count = 0;
        unordered_map<TreeNode* , bool> vis;
        q.push(temp);
        vis[temp] = true;

        while(!q.empty()){
            int len = q.size();
            bool flag = false;
            while(len--){
                auto top = q.front();
                q.pop();
                //check for left part
                if(top->left && !vis[top->left]){
                    q.push(top->left);
                    vis[top->left] = true;
                    flag = true;
                }

                //check for right part
                if(top->right && !vis[top->right]){
                    q.push(top->right);
                    vis[top->right] = true;
                    flag = true;
                }

                //check for parent part
                if (parent.find(top) != parent.end() && !vis[parent[top]]) {
                    q.push(parent[top]);
                    vis[parent[top]] = true;
                    flag = true;
                }
            }
                if(flag) count++;
        }
        return count;
    }
};