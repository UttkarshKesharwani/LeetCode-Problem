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

    pair<ListNode*,ListNode*> findMiddleNode(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prevSlow = NULL;

        while(fast and fast->next){
            prevSlow = slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        return {slow,prevSlow};
    }

    TreeNode* buildTree(ListNode* head){

        if(!head) return NULL; // empty linked list

        auto [mid,prev] = findMiddleNode(head);
    
        if(prev == NULL) { // Only one node in the list
            return new TreeNode(mid->val);
        }

        prev->next = NULL;  // Split the list
        TreeNode* root = new TreeNode(mid->val);
        
        root->left = buildTree(head);
        root->right = buildTree(mid->next);

        return root;
    }   

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);        
    }
};