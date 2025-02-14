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
    typedef unsigned long long  ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , ll>> q;
        q.push({root , 0});
        ll ans = 0;

        while(!q.empty()){
            ll n = q.size();
            ll l = q.front().second;
            ll r = q.back().second;

            while(n--){
                auto node = q.front();
                q.pop();

                if(node.first->left){
                    q.push({node.first->left , 2*node.second+1});
                }

                if(node.first->right){
                    q.push({node.first->right , 2*node.second+2});
                }
            }
            ans = max(ans , r-l+1);
        }
        return ans;
    }
};
