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
    
    bool result = false;
    
    bool canBlueWin(int blueVal,int redVal){
        return (blueVal>redVal)?false:true;
    }
    
    void dfs(TreeNode* root,int n,int x){
        if(root==NULL) return;
        int initialRootValue = root->val;
        dfs(root->left,n,x);
        dfs(root->right,n,x);
        int rightVal = (root->right==NULL)?0:root->right->val;
        int leftVal = (root->left==NULL)?0:root->left->val;
        root->val = 1 + rightVal + leftVal;
        
        if(initialRootValue==x){
            result = result or canBlueWin(root->val,n-root->val);
            if(root->left) result = result or canBlueWin(n-leftVal,leftVal);
            if(root->right) result = result or canBlueWin(n-rightVal,rightVal);
        }
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root,n,x);
        return result;
    }
};