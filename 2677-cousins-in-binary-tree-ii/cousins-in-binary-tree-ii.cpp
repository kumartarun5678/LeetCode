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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        vector<int>level;
        while(!q.empty()){
            TreeNode*curr = q.front();
            q.pop();
            if(curr == NULL){
                level.push_back(sum);
                sum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum += curr->val;
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
        }
        q.push(root);
        root->val = 0;
        int i = 1;
         while (i < level.size() && !q.empty()){
            int n = q.size();
            while(n--){
                TreeNode*curr = q.front();
                q.pop();
                int sumsib  = 0;
                if(curr->left != NULL){
                    sumsib+=curr->left->val;
                }
                
                if(curr->right!= NULL){
                    sumsib += curr->right->val;
                }
                
                if(curr->left != NULL){
                    curr->left->val = level[i] - sumsib;
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    curr->right->val = level[i] - sumsib;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};