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
     int ans = INT_MAX;
    void inOrder(TreeNode* currNode, TreeNode* itsParent){
        if(currNode==NULL) return ;
        inOrder(currNode->left,currNode);
        if(itsParent){
            int diff = abs(currNode->val-itsParent->val);
            ans = min(ans,diff);
        }
        inOrder(currNode->right,currNode);
    }
    int getMinimumDifference(TreeNode* root) {
        
        inOrder(root,NULL);
        return ans;
    }
};