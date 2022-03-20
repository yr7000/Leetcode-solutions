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
    int result = INT_MIN;
    
    int maxSumOfPathWithNoU(TreeNode* root){
        if(root==NULL) return 0;
        int l = maxSumOfPathWithNoU(root->left);
        int r = maxSumOfPathWithNoU(root->right);
        int maxPathSumForThisNode = root->val+max({0,l,r,l+r});
        result = max(result,maxPathSumForThisNode);
        return root->val + max({0,l,r});
    }
    
    int maxPathSum(TreeNode* root) {
        maxSumOfPathWithNoU(root);
        return result;
    }
};