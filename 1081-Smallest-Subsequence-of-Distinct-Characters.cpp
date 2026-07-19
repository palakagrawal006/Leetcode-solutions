class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map <int, int> mp ; 

        // store last occurance index 
        for(int i=0; i<s.size(); i++){
            mp[s[i]] = i ; 
        }

        string st ;
        vector <int> visited(26, 0) ;  

        for(int i=0; i<s.size(); i++){
            char c = s[i] ; 

            // agr phle se visited h to skip
            if(visited[c-'a']) continue ;

            while(!st.empty() &&  st.back()> c &&  mp[st.back()]>i){
                visited[st.back()-'a'] = 0 ; 
                st.pop_back() ; 
            }
          
            st.push_back(c) ;
            visited[c-'a'] = 1; 

        }

        return st ; 
    }
};