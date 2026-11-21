class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(); 
        queue<int> q ;

        for(int a : students){
            q.push(a) ; 
        }

        // to check repeat
        int c = 0 ; int i =0; 
        while(!q.empty()){
            if(q.front() == sandwiches[i]){
                q.pop() ; 
                c  = 0;
                i++;
            }
            else{
                int x = q.front() ; 
                q.pop() ;
                q.push(x) ;
                c++; 
            }
            if(c == q.size()) return q.size() ; 
        }
        return 0 ; 
    }
};