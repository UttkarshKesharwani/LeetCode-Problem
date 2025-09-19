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
    void display(vector<int> &ans){
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    int sizeAfterTrimmingNullNodes(const vector<int> &ans){
        int n = ans.size();
        int i = 0, j = n - 1;
        while (i < n && ans[i] == -1) i++;
        while (j >= 0 && ans[j] == -1) j--;
        return (i > j) ? 0 : (j - i + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int result = 0;

        while (!q.empty()) {

            int n = q.size();
            vector<int> ans;
           

            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front(); q.pop();

                if (curr == nullptr) {
                    ans.push_back(-1);
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    ans.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            int width = sizeAfterTrimmingNullNodes(ans);
            display(ans);

            if (width == 0) break; // most imp line 

            result = max(result, width);
        }

        return result;
    }
};
