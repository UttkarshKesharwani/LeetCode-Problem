
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            // iterative solution
            ListNode* curr=head;
            ListNode* Next=head;
            ListNode* prev=NULL;

            while(curr!=NULL){
                Next=Next->next;
                curr->next=prev;
                prev=curr;
                curr=Next;

            }
            return prev;
            
        
    }
};