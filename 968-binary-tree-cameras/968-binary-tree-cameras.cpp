class Solution {
public:
    int minCameras = 0;
    
    string getStateOf(TreeNode* root){
        // if the root is null, we can treat it as a covered state.
        if(root == NULL) return "covered";
		
        string leftChildState = getStateOf(root->left);
        string rightChildState = getStateOf(root->right);
		
        // if any child is not covered then there must be a camera here to cover them.
        if(leftChildState == "notCovered" or rightChildState == "notCovered"){
            minCameras++;
            return "camera";
        }
        // if any child has a camera on it then this node is covered.
        if(leftChildState == "camera" or rightChildState == "camera"){
            return "covered";
        }
        // if the above cases doesnt satisfy, this node's state is not covered.
        return "notCovered";
    }
    
    int minCameraCover(TreeNode* root) {
        string rootState = getStateOf(root);
        // if the state of root is not covered then we must place a camera on the root node.
        if(rootState == "notCovered"){
            minCameras++;
        }
        return minCameras;
    }
};