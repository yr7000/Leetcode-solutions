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
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    
    void dfs(TreeNode* root,vector<vector<int>> &result,int height,int level){
        if(root==NULL) return;
        result[height-level].push_back(root->val);
        dfs(root->left,result,height,level+1);
        dfs(root->right,result,height,level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<int>> result(height);
        dfs(root, result, height,1);
        return result;
    }
};