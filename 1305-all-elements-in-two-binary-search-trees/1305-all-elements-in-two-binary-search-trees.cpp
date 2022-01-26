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
    
    void inorder(TreeNode* root,vector<int>& traversal){
        if(root==NULL) return;
        inorder(root->left,traversal);
        traversal.push_back(root->val);
        inorder(root->right,traversal);
        return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorderRoot1;
        inorder(root1,inorderRoot1);
        vector<int> inorderRoot2;
        inorder(root2,inorderRoot2);
        vector<int> result;
        int i = 0, j = 0;
        while(i<inorderRoot1.size() and j<inorderRoot2.size()){
            if(inorderRoot1[i]<=inorderRoot2[j]){
                result.push_back(inorderRoot1[i]);
                i++;
            }else{
                result.push_back(inorderRoot2[j]);
                j++;
            }
        }
        while(i<inorderRoot1.size()) result.push_back(inorderRoot1[i++]);
        while(j<inorderRoot2.size()) result.push_back(inorderRoot2[j++]);
        return result;
    }
};