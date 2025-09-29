
class Solution {
public:
    int search(vector<int>& inorder, int start, int end, int target){
        for(int i=start;i<=end;i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preIdx, int low, int high){

        if(low > high) return NULL;

        int currNode = preorder[preIdx];
        TreeNode* root = new TreeNode(currNode);

        int inIdx = search(inorder,low,high,currNode);
        preIdx++;

        root->left = helper(preorder,inorder, preIdx,low,inIdx-1);
        root->right = helper(preorder,inorder, preIdx, inIdx+1,high);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder,inorder,preIdx,0,inorder.size()-1);
    }
};