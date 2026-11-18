
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head ;

        ListNode *first = head ;
        ListNode *second = head->next ;
        ListNode *prev = NULL  ;
        while(first && second){
            ListNode* nx = second->next ; 
            second->next = first; 
            first->next = nx ;
            if(prev) prev->next = second ; 
            else head= second;
           
           prev = first ; 
           first = nx ;
           if(nx ) second = nx->next ;
           else second = NULL ; 
        }
        return head;
    }
};