/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> ans;
    
    void traveseLL(ListNode* head){
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* buildTree(vector<int>& arr,int low ,int high){

        if(low>high) return NULL;

        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildTree(arr,low,mid-1);
        root->right = buildTree(arr,mid+1,high);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ans.clear();
        traveseLL(head);
        return buildTree(ans,0,ans.size()-1);
    }
};