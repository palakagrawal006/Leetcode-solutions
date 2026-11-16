class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* t = dummy;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val)
                    curr = curr->next;
                t->next = curr->next;
                curr = curr->next; 

            } else {
                t = t->next ;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};