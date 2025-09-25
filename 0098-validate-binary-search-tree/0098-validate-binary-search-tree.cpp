
class Solution {
public:

    bool isValid = true;
    long long prev = LLONG_MIN; // because in que node can be INT_MIN

    void inOrder(TreeNode* root){ // since inorder of BST is always sorted(do inorder and on the go check whether the curr value of node is smaller, if yes then it will not valid BST)
        if(root == NULL) return ;
        inOrder(root->left);
        if(root->val > prev){
            prev = root->val;
        }else{
            isValid = false;
        }
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return isValid; 
    }
};