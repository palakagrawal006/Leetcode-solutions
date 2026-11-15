
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        if(head==NULL)return {{}} ; 

        ListNode *temp = head;
        vector<vector<int>> v(m, vector<int> (n, -1)) ; 

        int minr = 0, minc = 0, maxc = n-1  , maxr= m-1 ;

        while(minr<= maxr && minc<=maxc && temp){
            // right
            for(int k =minc ; k<=maxc && temp!=NULL; k++){
                v[minr][k] = temp->val;
                temp = temp->next ; 
            }
            minr++;

            
            // DOWN
            for(int k =minr ; k<=maxr && temp!=NULL; k++){
                v[k][maxc] = temp->val;
                temp = temp->next ; 
            }
            maxc--;

            // left
            for(int k =maxc ; k>=minc && temp!=NULL; k--){
                v[maxr][k] = temp->val;
                temp = temp->next ; 
            }
            maxr--;

            // up
            for(int k =maxr ; k>=minr && temp!=NULL; k--){
                v[k][minc] = temp->val;
                temp = temp->next ; 
            }
            minc++;

        }
        return v ;
    }
};