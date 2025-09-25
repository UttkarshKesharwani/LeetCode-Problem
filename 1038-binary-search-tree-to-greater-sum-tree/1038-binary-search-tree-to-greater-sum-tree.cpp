/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i=0;
    void inOrder(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }

    void changeValueOfBST(TreeNode* root,vector<int>& ans){
        if(root == NULL) return;
        changeValueOfBST(root->left,ans);
        root->val = ans[i++];
        changeValueOfBST(root->right,ans);
    }

    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        inOrder(root,ans);

        for(int j=ans.size()-2;j>=0;j--) ans[j] = ans[j]+ans[j+1];

        changeValueOfBST(root,ans);

        return root;
    }
};