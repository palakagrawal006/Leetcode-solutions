
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(100);
        ListNode* temp = newHead;

        // if (!l1)
        //     return l2;
        // if (!l2)
        //     return l1;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        if (l1)
            temp->next = l1;
        if (l2)
            temp->next = l2;

        return newHead->next;
    }

    ListNode* partitionList(int h, int l, vector<ListNode*>& lists) {
        if (l == h)
            return lists[l];
        if (l > h)
            return NULL;

        int mid = l + (h - l) / 2;

        ListNode* l1 = partitionList(h, mid + 1, lists);
        ListNode* l2 = partitionList(mid,l, lists);

        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if(n==0) return NULL;

        return partitionList(n - 1, 0, lists);
    }
};