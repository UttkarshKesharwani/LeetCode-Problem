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
    bool isCousins(TreeNode* root, int x, int y) {

        unordered_map<int,TreeNode*> parent;  // <nodeVal,itsParentNode> for x and y
        unordered_map<int,int> level;

        queue<tuple<TreeNode*,TreeNode*,int>> q; // <currNode,itsParent,currLevel>

        q.push({root,NULL,0});

        while(!q.empty()){

            int n=q.size();

            for(int i=0;i<n;i++){

                auto [currNode,itsParent,currLevel] = q.front();
                q.pop();

                if(currNode->val==x || currNode->val==y){
                    parent[currNode->val] = itsParent;
                    level[currNode->val] = currLevel;
                }

                if(currNode->left) q.push({currNode->left,currNode,currLevel+1});
                if(currNode->right) q.push({currNode->right,currNode,currLevel+1});
            }
        }


        if(parent[x]!=parent[y] && level[x]==level[y]) return true;

        return false;
    }
};