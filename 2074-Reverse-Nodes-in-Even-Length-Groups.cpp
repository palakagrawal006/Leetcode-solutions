
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode *curr = head;
        ListNode *prev =NULL; 
        ListNode *nxt = NULL ;

        while(curr){
            nxt = curr->next ;
            curr->next = prev ;
            prev  = curr; 
            curr= nxt; 
        }
        return prev ; 
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *curr= head; 
        int group = 1; 
        ListNode *dummy = new ListNode(0) ; 
        dummy->next = head ;
        ListNode *t = dummy; 

        while(curr){
            int count = 1; 
            ListNode* temp = curr; 
            ListNode* groupHead = curr; 

            while(count< group && temp->next){
                count++;
                temp = temp->next ; 
            }
            ListNode *nx = temp->next; 
            temp->next = NULL;

            if(count%2 ==0 ){
               ListNode *newHead = reverse(groupHead) ; 
               t->next = newHead ;
               groupHead->next = nx ; 
               t = groupHead; 
            }
           else{
                t->next = groupHead ;
                temp->next = nx ; 
                t = temp;
           }
           curr = nx ;
            group++;
        }
        return dummy->next ;
    }
};