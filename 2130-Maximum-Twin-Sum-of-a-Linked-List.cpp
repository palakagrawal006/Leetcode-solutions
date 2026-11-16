
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
    int pairSum(ListNode* head) {
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

         ListNode* t1 = head;
         ListNode* t2 = rightHead;
         int sum = 0 ;
         int maxSum = 0 ;

         while(t1 && t2){
            sum = t1->val +t2->val ; 
            maxSum = max(sum , maxSum) ; 

            t1= t1->next ;
            t2= t2->next ;
         }

         return maxSum ;

    }
};