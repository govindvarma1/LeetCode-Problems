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

    int solve(TreeNode* root, int maxi) {
        if(root == nullptr) {
            return 0;
        }
        int ans = 0;
        if(root->val >= maxi) {
            ans++;
        }
        return ans + solve(root->right, max(root->val, maxi)) + solve(root->left, max(root->val, maxi));
    }

    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);        
    }
};