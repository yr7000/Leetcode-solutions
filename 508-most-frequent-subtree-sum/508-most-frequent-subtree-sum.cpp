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
    unordered_map<int,int> frequency;
    int maxFrequency = 0;
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int leftSubTreeSum = dfs(root->left);
        int rightSubTreeSum = dfs(root->right);
        int rootSubTreeSum = root->val + leftSubTreeSum + rightSubTreeSum;
        frequency[rootSubTreeSum]++;
        maxFrequency = max(maxFrequency,frequency[rootSubTreeSum]);
        return rootSubTreeSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> result;
        for(auto it:frequency){
            if(it.second == maxFrequency){
                result.push_back(it.first);
            }
        }
        return result;
    }
};