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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(root==NULL) return result;
        vector<int> level;
        q.push(root);
        q.push(NULL);
        while(q.size()>1){
            TreeNode* currentNode = q.front();
            q.pop();
            if(currentNode == NULL){
                result.push_back(level);
                level.clear();
                q.push(NULL);
            }else{
                level.push_back(currentNode->val);
                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }
        }
        result.push_back(level);
        return result;
    }
};