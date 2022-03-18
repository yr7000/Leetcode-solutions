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
    map<pair<TreeNode*,int>,int> dp;
    int maxAmount(TreeNode* root,bool tookParentMoney){
        if(root==NULL) return 0;
        if(dp.count({root,tookParentMoney})) return dp[{root,tookParentMoney}];
        int firstChoiseRobbery = maxAmount(root->left,false) + maxAmount(root->right,false);
        if(tookParentMoney){
            return dp[{root,tookParentMoney}] = firstChoiseRobbery;
        }
        int secondChoiseRobbery = root->val + maxAmount(root->left,true) + maxAmount(root->right,true);
        return dp[{root,tookParentMoney}] = max(firstChoiseRobbery,secondChoiseRobbery);
    }
    
    int rob(TreeNode* root) {
        return maxAmount(root,false);
    }
};