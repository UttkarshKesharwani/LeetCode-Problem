class Solution {
public:
    vector<list<int>> graph;

    void addEdge(int src, int dest , bool bi_dir=true){
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }

    void makeGraph(TreeNode* root){

        queue<pair<TreeNode* , TreeNode*>> q;
        q.push({root,NULL});

        while(!q.empty()){

            int n=q.size();

            for(int i=0;i<n;i++){

                auto const [currNode,itsParent] = q.front();
                q.pop();

                if(itsParent != NULL) addEdge(currNode->val,itsParent->val);

                if(currNode->left) q.push({currNode->left,currNode});
                if(currNode->right) q.push({currNode->right,currNode});
                
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {

        graph.resize(100000 + 5);
        makeGraph(root);

        // bfs start from here
        int time = 0;
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        q.push(-1);
        visited.insert(start);


        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == -1){
                if(!q.empty()){
                    q.push(-1);
                }
                time++;
            }
            else{
                for(auto neigh : graph[curr]){
                    if(not visited.count(neigh)){
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
            }
        }
        
        return time-1;
    }
};