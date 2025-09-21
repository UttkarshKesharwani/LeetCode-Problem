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

    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){

            int n=q.size();
            vector<int> ans;

            for(int i=0;i<n;i++){

                TreeNode* currNode = q.front();
                q.pop();
                ans.push_back(currNode->val);

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            
            for(auto ele:ans){
                cout<<ele<<" ";
            }
            cout<<endl;

            for(int i=0;i<ans.size();i++){
                if(level%2==0 ){ // even level
                    if(ans[i]%2==0) return false;  // must odd
                    if(i>0 && ans[i]<=ans[i-1]) return false;  // must increasing order
                }else{ // odd level
                    if(ans[i]%2!=0) return false; // must even
                    if(i>0 && ans[i]>=ans[i-1]) return false; // must decreasing order
                }
            }

            level++;

        }

        return true;
    }

};