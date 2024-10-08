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
    int maxsum;
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l = helper(root->left);
        int r = helper(root->right);

        int res = l+r+root->val;

        int ans = max(l,r)+root->val;
        int rootans = root->val;

        maxsum = max({maxsum,res,ans,rootans});

        return max(ans,rootans);
    }
    int maxPathSum(TreeNode* root) {
      maxsum = INT_MIN;
      helper(root);
      return maxsum;  
    }
};