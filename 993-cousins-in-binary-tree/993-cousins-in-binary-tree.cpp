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
    int depthOfX, depthOfY, parentOfX, parentOfY;
    void dfs(TreeNode* root,int depth,int x,int y,int parentValue){
        if(root==NULL) return;
        if(root->val == x){
            depthOfX = depth;
            parentOfX = parentValue;
        }
        if(root->val == y){
            depthOfY = depth;
            parentOfY = parentValue;
        }
        dfs(root->left,depth+1,x,y,root->val);
        dfs(root->right,depth+1,x,y,root->val);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,0,x,y,0);
        return depthOfX == depthOfY and parentOfX!=parentOfY;
    }
};