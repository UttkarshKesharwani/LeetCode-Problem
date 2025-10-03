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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(!root) return {};

        vector<vector<int>> result;

        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> ans;
            int n=q.size();

            for(int i=0;i<n;i++){
                auto currNode = q.front();
                q.pop();
                ans.push_back(currNode->val);

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }

            if(level % 2 == 1) reverse(ans.begin(), ans.end());
            result.push_back(ans);
            level++;
        }

        return result;
    }
};