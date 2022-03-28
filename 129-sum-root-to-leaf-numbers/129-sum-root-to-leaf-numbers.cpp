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
    int result = 0;
    
    int getSum(TreeNode* root, int currentPath){
        // add the current number to the current path
        currentPath = currentPath*10 + root->val;
        // if we reach a leaf node, add the current path value to the result
        if(root->right==NULL && root->left==NULL){
            return currentPath;
        }
        // recursively pass the currentPath to children
        int result = 0;
        if(root->left) result += getSum(root->left,currentPath);
        if(root->right) result += getSum(root->right,currentPath);
        return result;
    }
    
    int sumNumbers(TreeNode* root) {
        return getSum(root,0);
    }
};