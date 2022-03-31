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
    
    void getAllPaths(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &paths){
        if(root==NULL) return;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL and targetSum == root->val){
            paths.push_back(path);
        }
        getAllPaths(root->left,targetSum-root->val, path, paths);
        getAllPaths(root->right,targetSum-root->val, path, paths);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        getAllPaths(root, targetSum, path, paths);
        return paths;
    }
};