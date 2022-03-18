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
    
    int robHelper(TreeNode* root,int &left_rob,int &right_rob){
        if(root==NULL) return 0;
        int left_left_rob = 0, left_right_rob = 0, right_left_rob = 0, right_right_rob = 0;
        
        left_rob = robHelper(root->left,left_left_rob,left_right_rob);
        right_rob = robHelper(root->right,right_left_rob,right_right_rob);
        
        int choise1 = root->val + left_left_rob + left_right_rob + right_left_rob + right_right_rob;
        int choise2 = left_rob + right_rob;
        
        return max(choise1,choise2);
    }
    
    int rob(TreeNode* root) {
        int left_rob = 0, right_rob = 0;
        return robHelper(root,left_rob,right_rob);
    }
};