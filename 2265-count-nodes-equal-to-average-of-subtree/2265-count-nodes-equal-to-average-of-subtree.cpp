
class Solution {
public:

    int totalNodes=0;

    // for every nodes we are computing the average of its subtree
    pair<int,int> returnAverageOfSubtree(TreeNode* root){

        queue<TreeNode*> q;
        q.push(root);

        int totalSum = 0;
        int countNodes = 0;

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto currNode = q.front();
                q.pop();

                totalSum += currNode->val;
                countNodes++;

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }
        
        return {root->val,totalSum/countNodes};
    }

    void preOrder(TreeNode* root){
        if(root==NULL) return;
        preOrder(root->left);
        auto [rootVal,average] = returnAverageOfSubtree(root);
        if(rootVal==average) totalNodes++;
        preOrder(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        preOrder(root);
        return totalNodes;
    }
};