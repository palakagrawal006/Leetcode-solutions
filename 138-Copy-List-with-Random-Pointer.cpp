class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL ; 
        
        Node *temp = head->next ; 
        Node* newHead = new Node(head->val) ; 
        Node* t = newHead; //traverse

        while(temp){
            Node *newNode = new Node(temp->val) ; 
            t->next = newNode ; 
            t= t->next ;
            temp= temp->next ;
        }
        temp = head ; 
        t = newHead; 

        // make map of og nodes and duplicate node
        unordered_map <Node* , Node*> mp ; 

        while(temp && t){
            mp[temp] = t; 
            t= t->next ;
            temp = temp->next ; 
        }

        // make random connection 
        for(auto x : mp){
            Node *og = x.first;
            Node *copy = x.second ; 

            if(og->random !=NULL){
                Node *randomOg = og->random ; 
                Node *randomCopy = mp[randomOg] ; 

                copy->random = randomCopy; 
            }
            
        }
        return newHead; 
    }
};