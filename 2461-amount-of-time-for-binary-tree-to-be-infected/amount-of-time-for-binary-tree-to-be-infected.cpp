class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // Check if root is NULL
        if (!root) return 0;
        
        // BFS to find the parent of each node and locate the starting node
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* temp = NULL;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->val == start) {
                temp = node;
            }
            if (node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }

        // Perform BFS from the starting node to calculate the time taken to infect all nodes
        int count = 0;
        unordered_map<TreeNode*, bool> vis;
        q.push(temp);
        vis[temp] = true;

        while (!q.empty()) {
            int len = q.size();
            bool flag = false;
            for (int i = 0; i < len; ++i) {
                auto top = q.front();
                q.pop();
                // Check the left child
                if (top->left && !vis[top->left]) {
                    q.push(top->left);
                    vis[top->left] = true;
                    flag = true;
                }

                // Check the right child
                if (top->right && !vis[top->right]) {
                    q.push(top->right);
                    vis[top->right] = true;
                    flag = true;
                }

                // Check the parent
                if (parent.find(top) != parent.end() && !vis[parent[top]]) {
                    q.push(parent[top]);
                    vis[parent[top]] = true;
                    flag = true;
                }
            }
            if (flag) count++;
        }
        return count;
    }
};
