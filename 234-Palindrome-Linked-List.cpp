
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
    bool isPalindrome(ListNode* head) {
        // find left mid , reverse right part

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
           fast = fast->next->next;
           slow = slow->next ;
        }
        // slow will be in left mid

        ListNode *rightHead = reverseList(slow->next) ; 
        ListNode* t1 = head ;
        ListNode* t2 = rightHead ;

        while (t2) {
            if (t1->val != t2->val)
                return false;
            t1 = t1->next;
            t2 = t2->next;
        }
 
        return true;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         ListNode* nxt = NULL;

//         while (curr) {
//             nxt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
//         }

//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//         ListNode* newHead = new ListNode(100);

//         ListNode* t = head;
//         ListNode* t2 = newHead;

//         // deep copy
//         while (t) {
//             ListNode* n = new ListNode(t->val);
//             t2->next = n;
//             t2 = t2->next;
//             t = t->next;
//         }

//         newHead = reverseList(newHead->next);

//         t = head;
//         t2 = newHead;

//         while (t && t2) {
//             if (t->val != t2->val)
//                 return false;
//             t = t->next;
//             t2 = t2->next;
//         }
 
//         return true;
//     }
// };