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
    int solve(TreeNode* root, int targetSum,long long sum){
         if(root == NULL)
             return 0;
         sum+=root->val;
         return (sum == targetSum) + solve(root->left,targetSum,sum) + solve(root->right,targetSum,sum);
        
    }
    // void solve(TreeNode* root,int Target,vector<int>v,int &count){
    //     if(root == NULL)
    //          return;
        
    //     v.push_back(root->val);

    //     solve(root->left,Target,v,count);
    //     solve(root->right,Target,v,count);
        
    //   long sum=0;
    //     for(int i=v.size()-1;i>=0;i--){
    //          sum+=v[i];
    //          if(sum == Target)
    //              count++;
                 
    //     }
    //      v.pop_back();
    //}
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
           return 0;
        return  solve(root,targetSum,0) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
          

        //                             babar bhaiya trick

        // if (root ==NULL)
        //    return 0;
        // vector<int>v;
        // int count=0;
        // solve(root,targetSum,v,count);

        // return count;
    }
};