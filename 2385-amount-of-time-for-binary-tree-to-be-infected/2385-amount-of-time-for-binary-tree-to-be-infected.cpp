class Solution {
public:

    pair<TreeNode*,unordered_map<TreeNode*,TreeNode*>> makeParentPointer(TreeNode* root,int target){

        queue<pair<TreeNode*,TreeNode*>> q; // <currNode,itsParent>
        unordered_map<TreeNode*,TreeNode*> mp;  // <currNode,itsParent>

        TreeNode* targetRoot = NULL;

        q.push({root,NULL});

        while(!q.empty()){

            int n=q.size();

            for(int i=0;i<n;i++){

                auto const [currNode, itsParent] = q.front();
                q.pop();

                if(currNode->val == target){
                    targetRoot = currNode;
                }

                mp[currNode] = itsParent;

                if(currNode->left) q.push({currNode->left,currNode});
                if(currNode->right) q.push({currNode->right,currNode});
                
            }
        }

        return {targetRoot,mp};
    }

    int amountOfTime(TreeNode* root, int start) {

        pair<TreeNode*,unordered_map<TreeNode* ,TreeNode*>> p = makeParentPointer(root,start);

        TreeNode* targetRoot = p.first;
        unordered_map<TreeNode* ,TreeNode*> parent = p.second;

        unordered_set<int> visited;
        queue<TreeNode*> q;

        q.push(targetRoot);
        visited.insert(targetRoot->val);

        int time = 0;

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto currNode = q.front();
                q.pop();

                if(currNode->left && !visited.count(currNode->left->val)){
                    q.push(currNode->left);
                    visited.insert(currNode->left->val);
                }
                if(currNode->right && !visited.count(currNode->right->val)){
                    q.push(currNode->right);
                    visited.insert(currNode->right->val);
                }
                if(parent[currNode] && !visited.count(parent[currNode]->val)){  // make sure there is parent , edge case -> for root the parent is NULL
                    q.push(parent[currNode]);
                    visited.insert(parent[currNode]->val);
                }

            }

            time++;

        }       
        

        return time-1;
    }
};