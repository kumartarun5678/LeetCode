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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum = 0;
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<long long> level;
        while(!q.empty()){
            TreeNode* curr = q.front();
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
                if(curr->left!= NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
        }
        if(level.size()<k){
            return -1;
        }
        sort(level.rbegin(),level.rend());
        return level[k-1];
    }
};