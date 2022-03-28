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
    int result = 0;
    
    void sumNumbersHelper(TreeNode* root, string currentPath){
        char currentNumber = (char)(root->val+48);
        currentPath += currentNumber;
        if(root->right==NULL && root->left==NULL){
            result += stoi(currentPath);
            return;
        }
        if(root->left) sumNumbersHelper(root->left,currentPath);
        if(root->right) sumNumbersHelper(root->right,currentPath);
    }
    
    int sumNumbers(TreeNode* root) {
        sumNumbersHelper(root,"");
        return result;
    }
};