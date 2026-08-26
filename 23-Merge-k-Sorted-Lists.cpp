
class Solution {
public:
    typedef pair<int, ListNode*> v;
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int n = arr.size();

        priority_queue<v, vector<v>, greater<v>> pq;
        // val, listnode

        // push 1st element of each row
        for (int i = 0; i < n; i++) {
            if (arr[i] != NULL)
                pq.push({arr[i]->val, arr[i]});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            auto curr = pq.top();
            ListNode* node = curr.second;
            pq.pop();

            temp->next = node; // min node
            temp = temp->next;

            if (node->next != NULL)
                pq.push({node->next->val, node->next});
        }

        return dummy->next;
    }
};