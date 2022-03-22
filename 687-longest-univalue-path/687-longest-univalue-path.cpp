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
    
    int bestPossibleNodeCnt = 1;
    int longestNoUPath(TreeNode* root){
        if(root==NULL) return 0;
        int l = longestNoUPath(root->left);
        int r = longestNoUPath(root->right);
        if(root->left and root->left->val==root->val and root->right and root->right->val==root->val){
            bestPossibleNodeCnt = max(bestPossibleNodeCnt,1+l+r);
            return 1+max(l,r);
        }else if(root->left and root->left->val==root->val){
            bestPossibleNodeCnt = max(bestPossibleNodeCnt,1+l);
            return 1+l;
        }else if(root->right and root->right->val==root->val){
            bestPossibleNodeCnt = max(bestPossibleNodeCnt,1+r);
            return 1+r;
        }else{
            return 1;
        }
    }
    
    int longestUnivaluePath(TreeNode* root) {
        longestNoUPath(root);
        int length = bestPossibleNodeCnt-1;
        return length;
    }
};