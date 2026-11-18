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
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head->next ) return NULL;

        ListNode *temp = head->next; 
        ListNode *dummy = new ListNode(0) ;
        ListNode *t = dummy; 

        while(temp){
            int sum = 0 ;

            while(temp && temp->val !=0 ) {
                sum += temp->val ; 
                temp = temp->next ;
            }
            temp = temp->next ; 
            ListNode *n = new ListNode(sum);
            t->next = n ;
            t = t->next ; 

        }
        return dummy->next ;
    }
};