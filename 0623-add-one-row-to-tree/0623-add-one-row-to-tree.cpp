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
    void addRow(TreeNode* root,int val, int depth, int currDepth){
        if(root == NULL) return ;

        if(currDepth == depth-1){
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            
            root->left = new TreeNode(val);
            root->left->left = tempLeft;
            
            root->right = new TreeNode(val);
            root->right->right = tempRight;
        }
        addRow(root->left, val, depth, currDepth+1);
        addRow(root->right, val , depth, currDepth+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth==1){ 
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // if depth is not one
        addRow(root,val,depth,1);
        return root;
    }
};