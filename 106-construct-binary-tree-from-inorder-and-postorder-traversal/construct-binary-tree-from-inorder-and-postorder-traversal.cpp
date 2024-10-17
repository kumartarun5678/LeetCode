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
    void createmap(vector<int>&in, int n, map<int,int>&mpp){
        for(int i=0;i<n;i++){
            mpp[in[i]] = i;
        }
    }
    TreeNode* helper(vector<int>&in, vector<int>&po, int &pind, int ins, int ine, int n, map<int,int>&mpp ){
        if(pind<0 || ins>ine){
            return NULL;
        }
        int ele = po[pind--];
        TreeNode*root = new TreeNode(ele);

        int pos = mpp[ele];

        root->right = helper(in,po,pind,pos+1,ine,n,mpp);
        root->left = helper(in,po, pind, ins, pos-1,n,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n  = inorder.size();
        int pindex = n-1;
        map<int,int>mpp;
        createmap(inorder,n,mpp);
        TreeNode* ans = helper(inorder,postorder,pindex,0,n-1,n,mpp);
        return ans;
    }
};