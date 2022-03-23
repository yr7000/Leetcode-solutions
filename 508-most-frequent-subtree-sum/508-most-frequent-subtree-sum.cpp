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
    unordered_map<int,int> mp;
    unordered_map<int,vector<int>> freqVec;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int leftSubTreeSum = dfs(root->left);
        int rightSubTreeSum = dfs(root->right);
        int rootSubTreeSum = root->val + leftSubTreeSum + rightSubTreeSum;
        mp[rootSubTreeSum]++;
        freqVec[-mp[rootSubTreeSum]].push_back(rootSubTreeSum);
        return rootSubTreeSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL) return {};
        dfs(root);
        return freqVec.begin()->second;
    }
};