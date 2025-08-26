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
        ListNode* temp = dummy;

        while (!dq.empty()) {
            ListNode* front = dq.front();
            dq.pop_front();

            temp->next = front;
            temp = temp->next;

            if (!dq.empty()) {
                ListNode* back = dq.back();
                dq.pop_back();
                temp->next = back;
                temp = temp->next;
            }
        }

        temp->next = nullptr;   

        head = dummy->next;
        delete dummy;
    }
};
