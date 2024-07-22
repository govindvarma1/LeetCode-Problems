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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) {
            return result;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            int n = nodes.size();
            vector<int> temp;
            for(int i=0; i<n; i++) {
                TreeNode* curr = nodes.front();
                temp.push_back(curr->val);
                nodes.pop();
                if(curr->left != nullptr) {
                    nodes.push(curr->left);
                }
                if(curr->right != nullptr) {
                    nodes.push(curr->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};