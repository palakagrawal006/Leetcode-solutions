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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode *curr = head; 
        ListNode *prev = head; 

        while(curr && curr->next){
            if(curr->val == curr->next->val){
                curr = curr->next;
            }
            else{
                curr = curr->next;
                prev ->next = curr;
                prev = prev->next; 
            }  
        }
        prev->next = NULL;
        return head; 
    }
};