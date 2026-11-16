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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *d1 = new ListNode(0);
        ListNode *t1 = d1;
        ListNode *d2 = new ListNode(0);
        ListNode *t2 = d2;
        ListNode *temp = head;

        while(temp){
            t1->next  = temp ;
            if(temp)temp = temp->next ; 
            t1= t1->next ;

            t2->next = temp ; 
            if(temp)temp = temp->next;
            t2= t2->next;
        }
        // t2->next = NULL; 
        t1->next = d2->next ;
        return d1->next ;
    


    }
};