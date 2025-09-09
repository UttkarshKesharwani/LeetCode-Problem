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
    void solve(TreeNode* root, int targetSum,bool& isTrue){
        if(root==NULL ) return ;

        targetSum -=  root->val;

        if(targetSum==0 && root->left == NULL && root->right == NULL ){
            isTrue = true;
            return;
        }

        solve(root->left,targetSum, isTrue);
        solve(root->right,targetSum,isTrue);

        targetSum += root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isTrue = false;
        solve(root,targetSum,isTrue);
        return isTrue;
    }
};