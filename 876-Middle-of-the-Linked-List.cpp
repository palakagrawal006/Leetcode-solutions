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

// //  method 1 count
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode *temp = head; 
//         int count = 0; 
//         while(temp){
//             count++;
//             temp= temp->next ;
//         }

//         int mid = count/2; 
//         temp = head; 
//         while(mid){
//             mid--; 
//             temp = temp->next ;
//         }

//         return temp; 
//     }
// };

//  method 2 fast and slow
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head; 
        ListNode *slow = head; 
        
        while(fast && fast->next  ){
           slow= slow->next ;
           fast = fast->next->next ;
        }

        return slow ;
    }
};