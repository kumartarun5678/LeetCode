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
    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int n = helper(root->left);
        if (n == -1) { 
            return -1;
        }
        
        int m = helper(root->right);
        if (m == -1) {
            return -1;
        }
        
        if (abs(n - m) > 1) {
            return -1;
        }
        return max(n, m) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};