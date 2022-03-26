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
        // if tree is empty then there cant be any lca
        if(root==NULL) return NULL;
        // if the root value is equal to p node value or q node value 
        // then root is the lca
        if(root->val == p->val or root->val == q->val){
            return root;
        }
        // if p node value and q node value are greater than root node value 
        // then lca must exist in right child subtree
        if(p->val > root->val and q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        // if p node value and q node value are lesser than root node value
        // then lca must exist in left child subtree
        if(p->val < root->val and q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        // for any other case, root will be the lowest common ancestor.
        return root;        
    }
};