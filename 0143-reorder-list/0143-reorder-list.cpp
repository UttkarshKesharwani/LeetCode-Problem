class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next) return;

        deque<ListNode*> dq;
        ListNode* curr = head;
        
        while (curr) {
            dq.push_back(curr);
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0);
        curr = dummy;

        bool takeFront = true;

        while (!dq.empty()) {

            if(takeFront){
                ListNode* front = dq.front();
                dq.pop_front();
                curr->next = front;
            }else{
                ListNode* back = dq.back();
                dq.pop_back();
                curr->next = back;
            }
            
            curr = curr->next;
            takeFront = !takeFront;

        }

        curr->next = nullptr;   

        head = dummy->next;
        delete dummy;
    }
};
