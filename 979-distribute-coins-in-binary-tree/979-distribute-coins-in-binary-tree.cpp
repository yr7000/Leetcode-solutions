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
    int minMovesRequired = 0;
    
    // positive return value of this function indicates children giving the money to the parent
    // negative return value of this function indicates children requesting the money from the parent
    int getBalanceFrom(TreeNode* root){
        if(root==NULL) return 0;
        // getting the coins from both children in a recursive way
        int balanceFromLeftChild = getBalanceFrom(root->left);
        int balanceFromRightChild = getBalanceFrom(root->right);
        // movement of coins between children and the parent
        minMovesRequired += abs(balanceFromLeftChild) + abs(balanceFromRightChild);
        // returning the coins that it can give it to the parent node.
        return root->val + balanceFromLeftChild + balanceFromRightChild -1;
    }
    int distributeCoins(TreeNode* root) {
        getBalanceFrom(root);
        return minMovesRequired;
    }
};