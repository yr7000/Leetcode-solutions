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
    
    int pathSumHelper(TreeNode* root,long long currentSum,int targetSum,unordered_map<int,int> &prefixSum){
        if(root==NULL) return 0;
        currentSum += root->val;
        int numPathTillCurrent = prefixSum[currentSum-targetSum];
        prefixSum[currentSum]++;
        int result = numPathTillCurrent + pathSumHelper(root->left,currentSum,targetSum,prefixSum)+
            pathSumHelper(root->right,currentSum,targetSum,prefixSum);
        prefixSum[currentSum]--;
        return result;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int> prefixSum;
        prefixSum[0]++;
        return pathSumHelper(root,0,targetSum,prefixSum);
    }
};