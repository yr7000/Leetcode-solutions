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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(targetSum==root->val and root->left==NULL and root->right==NULL){
            return true;
        }
        bool checkInLeft = hasPathSum(root->left,targetSum-root->val);
        bool checkInRight = hasPathSum(root->right,targetSum-root->val);
        return checkInLeft or checkInRight;
    }
};