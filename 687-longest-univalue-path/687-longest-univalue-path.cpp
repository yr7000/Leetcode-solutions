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
    // stores the max node count
    int bestPossibleNodeCnt = 1;

    // required path: longest path with same value
    // No U path: a path where no 2 nodes in the path can have same parent
    // (No reverse U shape in the path).

    // this function returns: no U required path.
    int longestNoUPath(TreeNode* root){
        if(root==NULL) return 0;
        // get the no U required path passing through left child
        int l = longestNoUPath(root->left);
        // get the no U required path passing through right child
        int r = longestNoUPath(root->right);
        
        // update the bestPossibleNodeCnt if required
        // return the longest no u path passing through current tree node.
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
        // length = count-1
        int length = bestPossibleNodeCnt-1;
        return length;
    }
};