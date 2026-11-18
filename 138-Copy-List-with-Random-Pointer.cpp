class Solution {
public:
    int getIdx( Node *head, Node* rand){
        int idx = 0; 
        while(head){
            if(head == rand) return idx ;
            head= head->next ;
            idx++; 
        }
        return -1;
    }
    Node *getNode(Node *head , int idx){
        if(idx== 0) return head; 
        while(idx) {
            head = head->next ; 
            idx--; 
        }
        return head; 
    }
    Node* copyRandomList(Node* head) {
        if(!head)return head; 

        Node *temp = head; 
        Node *dummy = new Node (0) ; 
        Node *t = dummy; 

        while(temp){
            Node * n = new Node(temp->val) ; 
            t->next = n ; 
            t = t->next ; 
            temp = temp->next ;
        }

        // random connection 
        temp = head ; 
        t = dummy->next ; 
        while(temp && t){
            if(temp->random == NULL) t->random = NULL ;
            else { // temp ka random null nhi h 
            // get idx of temp-rand
                int idx = getIdx(head, temp->random ) ; 

                Node *rand = getNode(dummy->next , idx);
                t->random = rand;
            }

            temp = temp->next ; 
            t = t->next ;
        }

        return dummy->next ;
    }
};