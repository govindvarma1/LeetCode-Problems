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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return nullptr;
        } 
        if(root == p || root == q) {
            return root;
        }
        TreeNode* leftSub = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSub = lowestCommonAncestor(root->right, p, q);
        if(rightSub != nullptr && leftSub != nullptr) {
            return root;
        } else if(rightSub != nullptr) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};