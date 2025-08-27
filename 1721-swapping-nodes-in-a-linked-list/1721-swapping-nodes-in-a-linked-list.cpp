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
    ListNode* swapNodes(ListNode* head, int k) {


        ListNode* temp = head;
        int count = 0;

        while(temp){
            count++;
            temp = temp->next;
        }   

        int n = count-k+1;
        temp = head;  
        ListNode* kthNode = NULL;   // k-th from start
        ListNode* nthNode = NULL;   // k-th from end
        for(int i=1;i<=count;i++){
            if(i==k) kthNode = temp;
            if(i==n) nthNode = temp;
            temp = temp->next; 
        }

        
        swap(kthNode->val,nthNode->val);
       

        return head;

    }
};