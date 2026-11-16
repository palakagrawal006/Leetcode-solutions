
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo = new ListNode(100) ;
        ListNode* hi = new ListNode(100) ;
        ListNode* t1 = lo ;
        ListNode* t2 = hi ;
        ListNode* t = head ;

        while(t){
            if(t->val <x) {
                t1->next = t ; 
                t1 = t1->next ;
            }
            else {
                t2->next = t; 
                t2 = t2->next;
            }
            t = t->next;
        }
        t2->next = NULL ;
        t1->next = hi->next ; 
        return lo->next ; 


    }
};