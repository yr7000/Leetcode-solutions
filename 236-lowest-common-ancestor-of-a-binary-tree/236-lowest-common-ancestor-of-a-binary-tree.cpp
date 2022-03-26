/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if the tree is empty then there cant be any lca.
        if(root == NULL) return NULL;
        // if roots value is equal to p node or q node value then root must be lca
        if(root->val == p->val or root->val == q->val) return root;
        // else we will recursively check in the children subtrees.
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        // if one node is left child subtree and other node is in right child subtree then 
        // root must be lca
        if(l!=NULL and r!=NULL) return root;
        // if both two nodes are present in left child subtree
        if(l) return l;
        // if both nodes are present in right child subtree.
        return r;
    }
};