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
    int helper(TreeNode* root, int cnt){
        if(root == NULL){
            return cnt;
        }
       
       int left =  helper(root->left,cnt+1);
     
        int right = helper(root->right, cnt+1);
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {

        
        int ans =  helper(root,0);
        return ans;
    }
};