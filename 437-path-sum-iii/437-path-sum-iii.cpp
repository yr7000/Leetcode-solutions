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
    
    long long int pathSumHelper(TreeNode* root,long long int targetSum){
        if(root==NULL) return 0LL;
        long long int result = 0LL;
        if(root->val==targetSum) result++;
        result += pathSumHelper(root->left,targetSum-root->val);
        result += pathSumHelper(root->right,targetSum-root->val);
        return result; 
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int fromRoot = pathSumHelper(root,targetSum);
        int fromLeftChild = pathSum(root->left,targetSum);
        int fromRightChild = pathSum(root->right,targetSum);
        return fromRoot + fromLeftChild + fromRightChild;
    }
};