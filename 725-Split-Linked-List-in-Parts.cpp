
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // count size of linked list
        ListNode* temp = head; 
        int n = 0; 
        while(temp){
            temp = temp->next ;
            n++;
        }

        // size of each part of linked list
        int size = n/k ;
        int rem = n%k ;


        vector<ListNode*> ans ;
        temp = head;
        while(temp){
            ListNode *c = new ListNode(200) ;
            ListNode *t = c ;

            int s = size ; 
            if(rem >0) s++;
            rem--;

            while(s !=0 ){
                t->next = temp; 
                t= t->next ;
                temp = temp->next;
                s--;
            }
            t->next = NULL; 

            ans.push_back(c->next) ; 
        }

        if(ans.size()<k){
            int dif = k- ans.size() ; 

            for(int i= 1; i<= dif ; i++){
                ans.push_back(NULL) ;
            }
        }

        return ans ;
    }
};