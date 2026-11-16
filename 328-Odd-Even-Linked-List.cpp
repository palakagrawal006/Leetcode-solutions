
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head ;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = even;

        while(even && even->next){
            odd->next = odd->next->next ; 
            odd = odd->next ;

            even->next = even->next->next ; 
            even = even->next ;
        } 
        odd->next = temp ;
        return head ;

    }
};

// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         ListNode *d1 = new ListNode(0);
//         ListNode *t1 = d1;
//         ListNode *d2 = new ListNode(0);
//         ListNode *t2 = d2;
//         ListNode *temp = head;

//         while(temp){
//             t1->next  = temp ;
//             if(temp)temp = temp->next ; 
//             t1= t1->next ;

//             t2->next = temp ; 
//             if(temp)temp = temp->next;
//             t2= t2->next;
//         }
//         // t2->next = NULL; 
//         t1->next = d2->next ;
//         return d1->next ;

//     }
// };