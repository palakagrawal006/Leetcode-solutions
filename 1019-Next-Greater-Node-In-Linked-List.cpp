
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
    vector<int> nextLargerNodes(ListNode* head) {
        // reverse linked list -- find pge

        head= reversell(head) ;
    
        vector<int> ans ;
        stack<int> st ;
        ans.push_back(0) ; 
        st.push(head->val) ;
        head=  head->next;


        while(head){
            while(!st.empty() && st.top()<= head->val) st.pop() ; 

            if(st.empty()) ans.push_back(0);
            else ans.push_back(st.top()) ;

            st.push(head->val) ; 
            head = head->next ; 
        }

        reverse(ans.begin() , ans.end());
        return ans ; 
    }
};