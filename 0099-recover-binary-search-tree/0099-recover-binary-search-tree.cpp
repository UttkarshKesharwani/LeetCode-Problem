class Solution {
public:
    void inOrder(TreeNode* root, vector<pair<int,TreeNode*>>& arr){
        if(root == NULL) return;
        inOrder(root->left, arr);
        arr.push_back({root->val, root});
        inOrder(root->right, arr);
    }

    void recoverTree(TreeNode* root) {
        vector<pair<int,TreeNode*>> arr;
        inOrder(root, arr);

        int prev = -1;
        int next = -1;

        for(int i=0; i<arr.size()-1; i++){
            if(arr[i].first > arr[i+1].first){
                // If the two swapped nodes are next to each other (e.g., 1 2 5 4 6 7),
                if(prev == -1){
                    prev = i;
                    next = i+1;   
                }else{
                    //If the two swapped nodes are far apart (e.g., 1 2 8 4 5 6 7 3 9),
                    next = i+1;  
                }
            }
        }

        if(prev != -1 && next != -1){
            swap(arr[prev].second->val , arr[next].second->val);
        }
    }
};
