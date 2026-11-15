
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next ;
        if(!head) return head ;

        ListNode *curr = head ;
        ListNode *prev = NULL ;

        while(curr ){
            if(curr->val == val){
                prev->next = curr->next; 
                curr = curr->next ; 
            } 
            else{
                 prev= curr ;
                 curr = curr->next ;
            }
            
        }   
        return head ;
    }
};