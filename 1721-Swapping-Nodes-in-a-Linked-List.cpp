/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // kth node from end ; 

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i <k; i++) {
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
        // slow is having last kth 

        // first kth
        ListNode *first = head; 
        for(int i = 0; i<k-1; i++){
            first = first->next ; 
        }

        swap(first->val , slow->val) ;

        return head;
    }
};