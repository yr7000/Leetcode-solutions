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
    string getStateOf(TreeNode* root){
        if(root == NULL) return "covered";
        string leftChildState = getStateOf(root->left);
        string rightChildState = getStateOf(root->right);
        if(leftChildState == "notCovered" or rightChildState == "notCovered"){
            minCameras++;
            return "camera";
        }
        if(leftChildState == "camera" or rightChildState == "camera"){
            return "covered";
        }
        return "notCovered";
    }
    
    int minCameraCover(TreeNode* root) {
        string rootState = getStateOf(root);
        if(rootState == "notCovered"){
            minCameras++;
        }
        return minCameras;
    }
};