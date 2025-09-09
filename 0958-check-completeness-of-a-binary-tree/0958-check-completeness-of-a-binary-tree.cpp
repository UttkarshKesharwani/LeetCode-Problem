
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        bool past = false;  // kya maine koi bhi ane ke phle past me NULL dekha hua hai ?

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode == NULL){
                past = true;
            }else{
                if(past==true) return false;
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }

        return past;
    }
};