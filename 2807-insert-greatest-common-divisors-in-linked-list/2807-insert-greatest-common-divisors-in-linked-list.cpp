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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(!head->next) return head;

        ListNode* curr = head;
        ListNode* ahead = head->next;

        while(ahead){
            int g = gcd(curr->val,ahead->val); // built-in function
            ListNode* newNode = new ListNode(g);
            curr->next = newNode;
            newNode->next = ahead;
            curr = ahead;
            ahead = ahead->next;
        }

        return head;
    }
};