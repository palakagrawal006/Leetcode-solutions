

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i <=n; i++) {
            if(fast ==NULL) {
                head = head->next ;
                return head; 
            }
            fast = fast->next;
        }

        while (fast ) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // if(head->next == NULL && n==1) return NULL;

//         ListNode *temp = head;
//         int count = 0;
//         while(temp){
//             count++;
//             temp= temp->next ;
//         }

//         if(count == n) return head->next ;

//         int idx = count - n +1;
//         temp = head;

//         for(int i = 1; i<idx-1; i++){
//             temp = temp->next ;
//         }
//         temp->next = temp->next->next;
//         return head;    }
// };