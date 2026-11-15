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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1;
        ListNode *first ;
        ListNode *second ;

        int c = 0 ;
        while(temp){
            c++;
            if(c == a) first = temp ; 
            if(c == b +1) second = temp ;
            temp = temp->next ;  
        }
        first->next = list2; 

        temp = list2 ;
        while(temp->next){
            temp = temp->next ;  
        }

        temp->next = second->next ; 

        return list1;
    }
};