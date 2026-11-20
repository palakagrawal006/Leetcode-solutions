
class Solution {
public:
    ListNode *reversell(ListNode* head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nex = NULL;

        while(curr){
            nex = curr->next ;
            curr->next = prev ;
            prev = curr; 
            curr = nex ;
        }
        return prev ;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reversell(head) ;

        vector<int> ans ;
        stack<int> st ;
        // ans.push_back(0) ; 
        // st.push(head->val) ;
        // head=  head->next;


        while(head){
            while(!st.empty() && st.top()<= head->val) st.pop() ; 

            if(st.empty()) ans.push_back(-head->val); // negative
            else ans.push_back(st.top()) ;

            st.push(head->val) ; 
            head = head->next ; 
        }

        reverse(ans.begin() , ans.end());

        ListNode* dummy = new ListNode(0) ;
        ListNode* t = dummy; 

        for(int i = 0; i<ans.size() ; i++){
            if(ans[i]<0) {
                ListNode* n = new ListNode(-ans[i]) ; 
                t->next = n ;
                t = t->next ;
            }
        }
        t->next = NULL;
        return dummy->next  ; 
    }
};