
class Solution {
public:
    void attachNode(TreeNode* root,int val){
        if(root == NULL) return ;
        if(root->val > val){ // go left
            if(root->left == NULL){
                root->left = new TreeNode(val);
                return;
            }
            attachNode(root->left,val);
        }else{ // go right
            if(root->right == NULL){
                root->right = new TreeNode(val);
                return;
            }
            attachNode(root->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        attachNode(root,val);
        return root;
    }
};