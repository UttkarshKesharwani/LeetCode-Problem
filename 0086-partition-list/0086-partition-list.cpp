
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* low=new ListNode();
        ListNode* high=new ListNode();
        ListNode* templow=low;
        ListNode* temphigh=high; // Basically we are creating two lists jisme ek list me sare node ho jo ki x se less than ho aur doosre lists me x se greater than nodes present ho , fir use bad dono ko apas me connect kr dege 

        ListNode* temp=head;

        while(temp!=NULL){
            if(temp->val<x){
                templow->next=temp;
                temp=temp->next;
                templow=templow->next;
            }
            else{
                 temphigh->next=temp;
                temp=temp->next;
                temphigh=temphigh ->next;
            }
        }
        templow->next=high->next;
        temphigh->next=NULL;

        return low->next;


    }
};