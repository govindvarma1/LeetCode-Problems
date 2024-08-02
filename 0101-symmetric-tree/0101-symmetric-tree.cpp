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

    bool solve(TreeNode* r, TreeNode* l) {
        if(r == nullptr && l == nullptr) {
            return true;
        } else if (r == nullptr || l == nullptr) {
            return false;
        } 
        if(r->val != l->val) {
            return false;
        } 
        if(!solve(r->right, l->left) || !solve(r->left, l->right)){
            return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root->right, root->left);
    }
};