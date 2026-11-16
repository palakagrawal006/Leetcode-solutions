
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; 
        ListNode* prev = NULL; 
        ListNode* nxt = NULL;

        while(curr){
            nxt = curr->next ; 
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        } 

        return prev ;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        if(left == right) return head ; 
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int count = 1;

        while(temp){
            if(count  == left-1) a = temp ; 
            else if (count == left) b = temp; 
            else if (count == right) c = temp; 
            else if (count == right+1) d = temp;

            count++;
            temp = temp->next ;  
        }

        if(a)a->next = NULL;
        c->next = NULL ;

        c = reverseList(b) ;

        if(a) a->next  = c  ;
        b->next = d; 

        if(a)return head ;
        return c;


    }
};