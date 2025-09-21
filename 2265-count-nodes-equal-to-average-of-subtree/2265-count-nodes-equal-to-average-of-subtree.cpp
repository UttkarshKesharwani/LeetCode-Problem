
class Solution {
public:

    int count=0;

    pair<int,int> solve(TreeNode* root){

        if(root == NULL){
            return {0,0};  // {totalSum,totalNodes}
        }

        pair<int,int> p1 = solve(root->left);
        pair<int,int> p2 = solve(root->right);

        int totalSum = p1.first + p2.first + root->val;
        int totalNodes = p1.second + p2.second + 1;

        if(totalSum/totalNodes == root->val) count++;

        return {totalSum,totalNodes};
    } 
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};