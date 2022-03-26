/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    TreeNode* deserializeHelper(queue<string> &q){
        if(q.empty()) return NULL;
        string currentData = q.front();
        q.pop();
        if(currentData=="n") return NULL;
        TreeNode* currentNode = new TreeNode(stoi(currentData));
        currentNode->left = deserializeHelper(q);
        currentNode->right = deserializeHelper(q);
        return currentNode;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "n,";
        return to_string(root->val)+","+serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string str = "";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(str);
                str = "";
            }else{
                str += data[i];
            }
        }
        if(str.size()) q.push(str);
        return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));