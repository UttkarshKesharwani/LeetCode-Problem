
class Solution {
public:
    void insertIntoBST(TreeNode* root, int val){

        if(root == NULL) return ;

        if(root->val > val){ // go left

            if(root->left == NULL){
                root->left = new TreeNode(val);
                return ;
            }
            insertIntoBST(root->left,val);

        }else{ // go right

            if(root->right == NULL){
                root->right = new TreeNode(val);
                return ;
            }
            insertIntoBST(root->right,val);
            
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1;i<preorder.size();i++){
            insertIntoBST(root,preorder[i]);
        }

        return root;
    }
};