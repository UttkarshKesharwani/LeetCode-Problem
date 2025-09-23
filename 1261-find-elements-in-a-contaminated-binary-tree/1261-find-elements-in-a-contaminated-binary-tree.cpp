
class FindElements {
public:

    unordered_set<int> visited;

    FindElements(TreeNode* root) {

        queue<pair<TreeNode*,int>> q; // <currNode,itsValue>
        q.push({root,0});

        while(!q.empty()){

            int n=q.size();
            
            for(int i=0;i<n;i++){

                auto const [currNode,itsValue] = q.front();
                q.pop();

                currNode->val = itsValue;
                visited.insert(currNode->val);

                if(currNode->left) q.push({currNode->left,itsValue*2+1});
                if(currNode->right) q.push({currNode->right,itsValue*2+2});
                
            }
        }
    }
    
    bool find(int target) {
        return visited.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */