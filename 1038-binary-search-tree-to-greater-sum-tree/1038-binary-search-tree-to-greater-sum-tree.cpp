
class Solution {
public:
    int sum=0;
    void reverseInorder(TreeNode* root){
        // right root left
        if(root == NULL ) return ;
        reverseInorder(root->right);
        root->val = root->val + sum;
        sum=root->val;
        reverseInorder(root->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};