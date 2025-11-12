/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */


function binaryTreePaths(root: TreeNode | null): string[] {
    let ans: string[] = [];
    function dfs(node:TreeNode | null, path:string){
        if(!node){
            return ;
        }

        let newpath = path?`${path}->${node.val}`:`${node.val}`;

        if(!node.left && !node.right){
            ans.push(newpath);
            return;
        }

        dfs(node.left, newpath);
        dfs(node.right,newpath);
    }
    dfs(root, "");
    return ans ;
};