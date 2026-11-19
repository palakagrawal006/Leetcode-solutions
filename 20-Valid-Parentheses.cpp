class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2 != 0)return false;

        stack<char> st;

        for(char c : s){
            if(c=='(' || c=='{' || c=='[') st.push(c) ;
            else{
                if(st.empty()) return false;
                else if(c==')' && st.top()=='(') st.pop(); 
                else if(c=='}' && st.top()=='{') st.pop(); 
                else if(c==']' && st.top()=='[') st.pop(); 
                else return false; 
            }
        }
        if(st.empty()) return true;
        return false;
    }
};