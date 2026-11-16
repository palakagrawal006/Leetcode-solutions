// merge sort
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b ;
        if(!b) return a;

        if(a->val < b->val){
            a->next = merge(a->next , b) ; 
            return a; 
        }
        else{
            b->next = merge(a , b->next) ; 
            return b; 
        }
        return NULL;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        // divide from left middle using fast and slow

        ListNode* slow= head;
        ListNode* fast= head;


        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next; 
        }
        // slow will be in left middle

        // two list 
        ListNode *a = head;
        ListNode *b = slow->next;

        slow->next = NULL ;

        // sort  a and b
        a = sortList(a);
        b = sortList(b);

        // merge them
        ListNode *c = merge(a, b) ;
        return c ; 
    }
};