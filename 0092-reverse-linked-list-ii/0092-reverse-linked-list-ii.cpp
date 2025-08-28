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
    vector<ListNode*> reverseLL(ListNode* head){

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=curr;

        while(curr){
            Next = curr->next;
            curr->next  = prev;
            prev = curr;
            curr = Next;
        }

        return {prev,head}; // newHead, newTail
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        ListNode* behindLeft = NULL;
        for(int i=1;i<=left;i++){
            if(i==left) behindLeft = temp;
            temp = temp->next;
        }

        temp = dummy;
        for(int i=1;i<=right;i++){
            temp = temp->next;
        }

        ListNode* aheadRight = temp->next;

        ListNode* leftNode = behindLeft->next;
        ListNode* rightNode = temp;

        rightNode->next = NULL; // splitting LL from starting to end 

        vector<ListNode*> v= reverseLL(leftNode);
        ListNode* newHead = v[0];
        ListNode* newTail = v[1];

        behindLeft->next = newHead ;
        newTail->next = aheadRight;

        return dummy->next;
    }
};
