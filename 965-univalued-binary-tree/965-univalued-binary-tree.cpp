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
    
    int prevVal = -1;
    bool result = true;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prevVal!=-1 and root->val!=prevVal){
            result = false;
        }
        prevVal = root->val;
        inorder(root->right);
    }
    
    bool isUnivalTree(TreeNode* root) {
         inorder(root);
         return result;
    }
};