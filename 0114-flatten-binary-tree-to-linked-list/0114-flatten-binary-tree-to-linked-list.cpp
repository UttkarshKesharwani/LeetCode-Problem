class Solution {
public:

    vector<TreeNode*> ans;

    void preOrder(TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }

    void flatten(TreeNode* root) {
        if(!root) return;

        ans.clear();
        preOrder(root);

        for(int i=1;i<ans.size();i++){
            ans[i-1]->right = ans[i];
            ans[i-1]->left = NULL;
        }
    }
};
