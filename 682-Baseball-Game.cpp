class Solution {
public:
    int calPoints(vector<string>& arr) {
        int n  = arr.size() ;
        stack<int> st;

        for(string x : arr){
            if(!st.empty() && x == "+"){
                int first = st.top() ;
                st.pop() ;
                int sec = st.top() ;
                st.push(first) ; 

                st.push(first+sec) ; 
            }
            else if(!st.empty() && x == "D"){
                int first = st.top() ;
                st.push(first*2) ;
            }
            else if(!st.empty() && x == "C"){
                st.pop();
            }
            else{
                int num = stoi(x) ; 
                st.push(num) ; 
            }
        }

        int ans= 0;
        while(!st.empty()){
            ans += st.top() ; 
            st.pop() ;
        }

        return ans ;
    }
};