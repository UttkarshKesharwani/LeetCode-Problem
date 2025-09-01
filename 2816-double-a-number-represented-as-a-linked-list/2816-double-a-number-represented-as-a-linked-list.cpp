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
    ListNode* reverseLL(ListNode *head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head;

        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }


    ListNode* doubleIt(ListNode* head) {

        // 1->8->9   becomes --->     9->8->1

        ListNode* newHead = reverseLL(head);
        ListNode* temp = newHead;

        int carry = 0;

        while(temp){
            int val = temp->val*2 + carry;   
            temp->val = val % 10;
            carry = val / 10;

            if(!temp->next && carry){       
                temp->next = new ListNode(carry);
                break;                        
            }
            temp = temp->next;      
        }

        return reverseLL(newHead);
    }
};
