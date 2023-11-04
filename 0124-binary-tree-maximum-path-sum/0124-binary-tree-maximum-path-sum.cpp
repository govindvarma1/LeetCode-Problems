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
    int calc(TreeNode* root,int& ans){
        if(root == nullptr) {
            return 0;
        } 
        if(root->right==nullptr && root->left==nullptr)
        {         
            ans = max(ans, root->val);  
            return root->val;
        }
        int right = calc(root->right, ans);
        int left = calc(root->left, ans);
        ans = max(ans, max(root->val, max(root->val + max(right, left), root->val+ right +left)));
        return max(root->val, max(left, right)+ root->val);
    }


    int maxPathSum(TreeNode* root) {
        if(root->right==nullptr && root->left==nullptr) {
            return root->val;
        }
        int ans = INT_MIN;
        calc(root, ans);
        return ans;
    }
};