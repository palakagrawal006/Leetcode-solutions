
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = 0;
        ListNode* t1 = headA;
        while (t1) {
            len1++;
            t1 = t1->next;
        }

        int len2 = 0;
        ListNode* t2 = headB;
        while (t2) {
            len2++;
            t2 = t2->next;
        }
      
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                headA = headA->next;
            }
        }
        if (len1 < len2) {
            for (int i = 0; i < len2 - len1; i++) {
                headB = headB->next;
            }
        }

        t1= headA;
        t2 = headB ; 

        while(t1 && t2){
            if(t1 == t2)return t1;
            t1 = t1->next ;
            t2 = t2->next; 
        }

        return NULL ;


    }
};