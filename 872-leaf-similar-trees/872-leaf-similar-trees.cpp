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
    
    string getSequence(TreeNode* root){
        if(root==NULL) return "";
        if(root->left==NULL and root->right==NULL) return to_string(root->val)+" ";
        return getSequence(root->left) + getSequence(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string firstLeafSequence = getSequence(root1);
        string secondLeafSequence = getSequence(root2);
        return firstLeafSequence == secondLeafSequence;
    }
};