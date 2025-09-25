
class Solution {
public:

    int countNodes(ListNode* head , int count){
        while(head){
            count++;
            head = head->next;
        }
        return count++;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans;
        int count = countNodes(head,0);
        vector<int> sizes(k,count/k);

        for(int i=0;i<(count%k);i++) sizes[i]++;

        ListNode* curr = head;
        for(int i=0;i<k;i++){
            
            ans.push_back(curr);

            int partSize = sizes[i];
            
            for(int i=0;i<partSize-1;i++)
                curr = curr->next;

            // breaking the linked list
            if(curr){
                ListNode* nextPart = curr->next;
                curr->next = NULL;
                curr = nextPart;
            }
        }
    
        return ans;
    }
};