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

    vector<list<int>> graph;

    void addEdge(int src, int dest ,bool bi_dir=true){
        graph[src].push_back(dest);
        if(bi_dir){
            graph[dest].push_back(src);
        }
    }

    void makeGraph(TreeNode* root){

        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});  // case to handle

        while(!q.empty()){

            int n = q.size();

            for(int i=0;i<n;i++){

                const auto [currNode, itsParent] = q.front();
                q.pop();

                if(itsParent != NULL) addEdge(currNode->val,itsParent->val);

                if(currNode->left) q.push({currNode->left,currNode});
                if(currNode->right) q.push({currNode->right,currNode});

            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        graph.resize(10005); 
        makeGraph(root);

        // bfs traversal starts form here 
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        q.push({target->val,0});
        visited.insert(target->val);

        while(!q.empty()){

            const auto [currNode,currLevel]  = q.front();
            q.pop();

            if(currLevel == k){
                ans.push_back(currNode);
                continue;
            }
            
            for(auto neigh : graph[currNode]){
                if(not visited.count(neigh)){
                    q.push({neigh,currLevel+1});
                    visited.insert(neigh);
                }
            }   
        }

        return ans;
    }
};