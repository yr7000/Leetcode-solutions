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
    int minCameras = 0;
    string dfs(TreeNode* root){
        if(root == NULL) return "covered";
        string leftTreeState = dfs(root->left);
        string rightTreeState = dfs(root->right);
        if(leftTreeState == "notCovered" or rightTreeState == "notCovered"){
            minCameras++;
            return "camera";
        }
        if(leftTreeState == "camera" or rightTreeState == "camera"){
            return "covered";
        }
        return "notCovered";
    }
    
    int minCameraCover(TreeNode* root) {
        string rootState = dfs(root);
        if(rootState == "notCovered"){
            minCameras++;
        }
        return minCameras;
    }
};