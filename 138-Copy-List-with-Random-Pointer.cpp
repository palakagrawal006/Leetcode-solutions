// Time: O(n)  Space: O(1) (excluding copied nodes)
class Solution {
public:
   
    Node* copyRandomList(Node* head) {
        if(!head)return head; 

        Node *temp = head->next; 
        Node *newHead = new Node (head->val) ; 
        Node *t = newHead; 

        while(temp){
            Node * n = new Node(temp->val) ; 
            t->next = n ; 
            t = t->next ; 
            temp = temp->next ;
        }

        // random connection 
        temp = head ; 
        t = newHead ; 
        Node *dummy = new Node(0) ; 
        Node *d  = dummy ;
        while(temp && t){
            d->next = temp ; //og
            temp = temp->next ; 
            d = d->next ; 

            d->next = t ; // copy
            t = t->next ;
            d = d->next ; 
        }
        dummy = dummy->next ; 
        Node *t1 = dummy;  // og in dummy
        while(t1){
             Node *t2 = t1->next ; 
            if(t1->random) t2->random = t1->random->next ; 
            t1= t2->next ;
        }
        // t1->next = NULL;
        

        Node *d1 = new Node(0) ; 
        Node *d2 = new Node(0)  ;
        t1= d1;
        Node *t2  = d2 ;
        d = dummy; 
        while(d){
            t1->next = d; 
            d = d->next ; 
            t1 = t1->next ; 

            t2->next = d; 
            d = d->next ;
            t2 = t2->next ;  
        } 
        t1->next = NULL;
        t2->next = NULL;
        return d2->next ;
    }
};



// // Time: O(n²)  Space: O(1) (excluding copied nodes)
// class Solution {
// public:
//     int getIdx( Node *head, Node* rand){
//         int idx = 0; 
//         while(head){
//             if(head == rand) return idx ;
//             head= head->next ;
//             idx++; 
//         }
//         return -1;
//     }
//     Node *getNode(Node *head , int idx){
//         if(idx== 0) return head; 
//         while(idx) {
//             head = head->next ; 
//             idx--; 
//         }
//         return head; 
//     }
//     Node* copyRandomList(Node* head) {
//         if(!head)return head; 

//         Node *temp = head; 
//         Node *dummy = new Node (0) ; 
//         Node *t = dummy; 

//         while(temp){
//             Node * n = new Node(temp->val) ; 
//             t->next = n ; 
//             t = t->next ; 
//             temp = temp->next ;
//         }

//         // random connection 
//         temp = head ; 
//         t = dummy->next ; 
//         while(temp && t){
//             if(temp->random == NULL) t->random = NULL ;
//             else { // temp ka random null nhi h 
//             // get idx of temp-rand
//                 int idx = getIdx(head, temp->random ) ; 

//                 Node *rand = getNode(dummy->next , idx);
//                 t->random = rand;
//             }

//             temp = temp->next ; 
//             t = t->next ;
//         }

//         return dummy->next ;
//     }
// };