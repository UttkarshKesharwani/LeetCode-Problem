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

    void preOrder(vector<int>& arr, TreeNode* root){
        
        if (root == NULL) return; 

        if(root->left==NULL && root->right==NULL){
            arr.push_back(root->val);
            return ;
        }
        preOrder(arr,root->left);
        preOrder(arr,root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        preOrder(v1,root1);
        preOrder(v2,root2);

        return v1==v2;
    }
};