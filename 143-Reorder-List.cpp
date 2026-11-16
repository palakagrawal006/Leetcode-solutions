
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
         // find left mid , reverse right part

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
           fast = fast->next->next;
           slow = slow->next ;
        }
        // slow will be in left mid

        ListNode *rightHead = reverseList(slow->next) ;
        slow->next = NULL;
         
        ListNode* t1 = head ;
        ListNode* t2 = rightHead ;

        ListNode* newHead = new ListNode(100) ; 
        ListNode *temp = newHead ;

        while(t1 && t2){
            temp->next = t1 ;
            temp = temp->next;
            t1 = t1->next ;

            temp->next = t2 ;
            temp = temp->next;
            t2 = t2->next ;
        }

        
        if(t1) temp->next = t1;
        if(t2) temp->next = t2;

        head = newHead->next ; 

    }
};