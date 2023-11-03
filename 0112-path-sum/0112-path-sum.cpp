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

    int solve(TreeNode* root, vector<int>& nodes, int targetSum) {
        if(root->left == nullptr && root->right == nullptr) {
            nodes.push_back(root->val);
            int sum =0;
            for(int i=0; i<nodes.size(); i++) {
                sum+=nodes[i];
            }
            nodes.pop_back();
            if(sum == targetSum) {
                return true;
            } else {
                return false;
            }
        }
        bool right =false;
        bool left = false;
        nodes.push_back(root->val);
        if(root->left!=nullptr) {
            left = solve(root->left, nodes, targetSum);
        }
        if(root->right!=nullptr) {
            right = solve(root->right, nodes, targetSum);
        };
        nodes.pop_back();
        return left | right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        vector<int> nodes;
        return solve(root, nodes, targetSum);
    }
};