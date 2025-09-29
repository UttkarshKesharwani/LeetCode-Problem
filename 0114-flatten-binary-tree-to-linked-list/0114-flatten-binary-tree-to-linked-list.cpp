
class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;

        // with help of modified morris traversal
        while(curr!=NULL){

            if(curr->left!=NULL){

                TreeNode* pred = curr->left;
                TreeNode* rootOfRST = curr->right;  // root node of right sub tree
                
                while(pred->right!=NULL){
                    pred = pred->right;
                }

                pred->right = rootOfRST;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;

            }else{
                curr = curr->right;
            }
        }

    }
};