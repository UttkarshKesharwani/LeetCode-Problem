
class Solution {
public:

    unordered_map<TreeNode*,TreeNode*> parent; //<currNode,itsParent>

    void makeParentMap(TreeNode* currNode,TreeNode* itsParent){
        if(currNode==NULL) return;
        parent[currNode] = itsParent;
        makeParentMap(currNode->left,currNode);
        makeParentMap(currNode->right,currNode);
    }

    void display(){
        for(auto ele:parent){
            if(ele.second == NULL) cout<<ele.first->val<<"->"<<"NULL";
            else cout<<ele.first->val<<"->"<<ele.second->val<<endl;
        }
    }

    TreeNode* findLCA(TreeNode* p, TreeNode* q){
        
        // Store ancestors of p
        unordered_set<TreeNode*> ancestors ;

        while(p!=NULL){
            ancestors.insert(p);
            p = parent[p];
        }

        // Move q upwards until we meet an ancestor of p
        while(q!=NULL){
            if(ancestors.count(q)) return q;
            q = parent[q];
        }

        // this line will never reaches
        return NULL;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        makeParentMap(root,NULL);
        return findLCA(p,q);
    }
};