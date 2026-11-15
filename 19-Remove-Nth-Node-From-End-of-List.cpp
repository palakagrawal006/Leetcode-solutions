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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head->next == NULL && n==1) return NULL; 

        ListNode *temp = head; 
        int count = 0; 
        while(temp){
            count++;
            temp= temp->next ;
        }

        if(count == n) return head->next ;

        int idx = count - n +1; 
        temp = head; 

        for(int i = 1; i<idx-1; i++){
            temp = temp->next ;
        }
        temp->next = temp->next->next; 
        return head;    }
};