
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    //    recursive

    if(!head || !head->next) return head;

    ListNode *newHead = reverseList(head->next) ; //last ele

    head->next->next = head; 
    head->next = NULL ;

    return newHead; 
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* curr = head; 
//         ListNode* prev = NULL; 
//         ListNode* nxt = NULL;

//         while(curr){
//             nxt = curr->next ; 
//             curr->next = prev ;
//             prev = curr ;
//             curr = nxt ;
//         } 

//         return prev ;
//     }
// };