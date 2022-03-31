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
    // stores all the paths with sum as target sum.
    vector<vector<int>> result;
    
    // gets the path values vector
    vector<int> getPathVector(vector<pair<int,int>> &path){
        vector<int> pathValues;
        for(int i=0;i<path.size();i++){
            pathValues.push_back(path[i].first);
        }
        return pathValues;
    }
    
    void getAllPaths(TreeNode* root, int targetSum, vector<pair<int,int>> path){
        if(root==NULL) return;
        // include the current node in the path
        int pathSum = path.size()==0 ? root->val : root->val + path.back().second;
        path.push_back({root->val, pathSum});
        // if current node is a leaf node and path sum is target sum 
        // then add this path to result.
        if(root->left==NULL and root->right == NULL and pathSum == targetSum){
            result.push_back(getPathVector(path));
            return;
        }
        // recursively pass the path to the children
        getAllPaths(root->left, targetSum, path);
        getAllPaths(root->right, targetSum, path);
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // path[i].first contains the node value
        // path[i].second contains the path sum till the current node
        vector<pair<int,int>> path;
        getAllPaths(root,targetSum,path);
        return result;
    }
};