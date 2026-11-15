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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }

        k = k % n;
        if(k==0) return head;

        temp = head;
        int idx = n - k;
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }
        ListNode* a = temp;
        ListNode* b = temp->next; // new head

        while (temp->next) {
            temp = temp->next;
        }
        ListNode* c = temp;

        a->next = NULL;
        c->next = head;
        return b;
    }
};