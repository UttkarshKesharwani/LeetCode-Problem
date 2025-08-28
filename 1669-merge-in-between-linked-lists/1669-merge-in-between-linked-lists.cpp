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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* temp = list1;
        ListNode* beforeAthNode = NULL;
        for(int i=0; i<max(a,b);i++){
            if(i==a-1) beforeAthNode = temp;
            temp = temp->next;
        }
         
        beforeAthNode->next = list2;
        ListNode* afterBthNode = temp->next;

        while(list2->next){
            list2 = list2->next;
        }

        list2->next = afterBthNode;

        return list1;
    }
};