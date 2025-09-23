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

    int minStepToSortArray(vector<int>& arr){

        vector<int> sortArray = arr;
        int n=arr.size();
        int swaps = 0;
        unordered_map<int,int> mp; // {ele,idx} for array 'arr', to keep the track that where the index of particular ele exist

        sort(sortArray.begin(),sortArray.end());

        for(int i=0; i<n; i++) mp[arr[i]] = i;
        
        for(int i=0; i<n ;i++){
            if(sortArray[i] == arr[i]) continue;
            else{
                // sortArray[i] != arr[i];
                int j=mp[sortArray[i]];
                mp[arr[i]] = j;
                swap(arr[i],arr[j]);
                mp[arr[i]] = i;
                swaps++;
            }
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int minSwaps=0;

        while(!q.empty()){

            int l = q.size(); 
            vector<int> levelNode;

            for(int i=0;i<l;i++){

                TreeNode* node=q.front();
                q.pop();
                levelNode.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);    
            }

            minSwaps += minStepToSortArray(levelNode);

        }

        return minSwaps;
    }
};