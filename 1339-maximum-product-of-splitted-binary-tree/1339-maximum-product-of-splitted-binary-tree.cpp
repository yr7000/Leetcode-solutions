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
# define mod 1000000007
class Solution {
public:
    
    void replaceValByProduct(TreeNode* root){
        if(root==NULL) return;
        replaceValByProduct(root->left);
        replaceValByProduct(root->right);
        if(root->left) root->val += root->left->val;
        if(root->right) root->val += root->right->val;
    }
    long int getMaxProduct(TreeNode* root,long int totalSum){
        if(root==NULL) return 1;
        long int choise1 = (root->val * (totalSum-root->val));
        long int choise2 = getMaxProduct(root->left,totalSum);
        long int choise3 = getMaxProduct(root->right,totalSum);
        return max({choise1,choise2,choise3});
    }
    int maxProduct(TreeNode* root) {
        replaceValByProduct(root);
        long int totalSum = root->val;
        return max(getMaxProduct(root->left,totalSum),getMaxProduct(root->right,totalSum))%mod;
    }
};