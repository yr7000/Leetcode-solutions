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
    // stores the max number of nodes in a path.
    int maxNodesInPath = 0;
    
    int maxNoUPathLength(TreeNode* root){
        // no u path cant pass through a null node so the length is 0
        if(root==NULL) return 0;
        // max length of no u path passing through left child
        int l = maxNoUPathLength(root->left);
        // max length of no u path passing through right child
        int r = maxNoUPathLength(root->right);
        // updating the max nodes cnt in a path if required
        maxNodesInPath = max(maxNodesInPath,1+l+r);
        // return the max length of no u path passing through current node
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxNoUPathLength(root);
        // diameter = edges in the longest path between leaf
        // edges = num of nodes - 1
        int diameter = maxNodesInPath-1;
        return diameter;
    }
};