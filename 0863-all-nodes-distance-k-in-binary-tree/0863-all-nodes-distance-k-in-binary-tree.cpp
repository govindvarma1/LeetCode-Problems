/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void findParents(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current->right) {
                parent[current->right] = current;
                q.push(current->right);
            }
            if(current->left) {
                parent[current->left] = current;
                q.push(current->left);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        findParents(parent, root);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        int curr_level = 0;
        visited[target] = true;

        while(!q.empty()) {
            int size = q.size();
            if(curr_level++ == k) {
                break;
            }
            for(int i=0; i<size; i++) {
                TreeNode* current = q.front();
                visited[current] = true;
                q.pop();

                if(current->left && !visited[current->left]) {
                    q.push(current->left);
                }
                if(current->right && !visited[current->right]) {
                    q.push(current->right);
                }
                if(parent[current] && !visited[parent[current]]) {
                    q.push(parent[current]);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* current = q.front();
            ans.push_back(current->val);
            q.pop();
        }
        return ans;
    }
};