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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> s(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(head){
            if(!s.contains(head->val)){
                ListNode* newNode = new ListNode(head->val);
                temp->next = newNode;
                temp = temp->next;
            }
            head = head->next;
        }

        temp->next = NULL;


        return dummy->next;

    }
};