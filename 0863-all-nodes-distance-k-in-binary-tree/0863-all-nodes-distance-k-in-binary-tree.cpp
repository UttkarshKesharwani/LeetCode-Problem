/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> makeParentPointer(TreeNode* root){

        queue<pair<TreeNode*,TreeNode*>> q;
        unordered_map<TreeNode*,TreeNode*> parent; // <currNode,itsParent>

        q.push({root,NULL});

        while(!q.empty()){

            int n=q.size();

            for(int i=0;i<n;i++){

                auto const [currNode , itsParent] = q.front();
                q.pop();
                parent[currNode] = itsParent;

                if(currNode->left) q.push({currNode->left,currNode});
                if(currNode->right) q.push({currNode->right,currNode});
                
            }
        }

        return parent;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        unordered_map<TreeNode*,TreeNode*> parent = makeParentPointer(root) ; 

      
        queue<pair<TreeNode*,int>> q; // <node,itsCurrentLevel>
        q.push({target,0});

        unordered_set<int> visited;  // track whether the immideate neighbour is processed or not
        visited.insert(target->val);

        while(!q.empty()){

            int n=q.size();

            for(int i=0;i<n;i++){

                auto const [currNode,currLevel] = q.front();
                q.pop();

                cout<<currNode->val<<" ";

                if(currLevel == k){
                    ans.push_back(currNode->val);
                    continue;
                }

                if(currNode->left && !visited.count(currNode->left->val)){
                    q.push({currNode->left,currLevel+1});
                    visited.insert(currNode->left->val);
                }
                if(currNode->right && !visited.count(currNode->right->val)){
                    q.push({currNode->right,currLevel+1});
                    visited.insert(currNode->right->val);
                }
                if(parent[currNode] && !visited.count(parent[currNode]->val) ){
                    q.push({parent[currNode],currLevel+1});
                    visited.insert(parent[currNode]->val);
                }
            
            }
           
        }

        return ans;
    }
};