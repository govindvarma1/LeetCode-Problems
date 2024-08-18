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
private: 

    int  ind  = 0;

    TreeNode* buildTree(vector<int>& preorder, map<int, int>& hashMap, int start, int end) {
        if(ind >= preorder.size() || start > end) {
            return nullptr;
        }
        int element = preorder[ind++];
        TreeNode* root = new TreeNode(element);
        root->left = buildTree(preorder, hashMap, start, hashMap[element]-1);
        root->right = buildTree(preorder, hashMap, hashMap[element] + 1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hashMap;
        for(int i=0; i<inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, hashMap, 0, preorder.size());
        return root;
    }
};