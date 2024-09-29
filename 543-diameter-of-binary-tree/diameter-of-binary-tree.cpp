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
    int helper(TreeNode* root,int &cnt){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left,cnt);
        int right = helper(root->right, cnt);
        cnt = max(left+right,cnt);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 0;
        helper(root,cnt);
        return cnt;
    }
};