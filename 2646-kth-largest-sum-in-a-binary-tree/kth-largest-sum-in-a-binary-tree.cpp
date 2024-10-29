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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        priority_queue<long long>pq;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int len = q.size();
            long long sum = 0;
            for(int i = 0 ; i < len ; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(sum);
        }
        // while(!pq.empty()){
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        while(k-1 && !pq.empty()){
            pq.pop();
            k--;
        }
        return pq.empty() ? -1 : pq.top();
    }
};