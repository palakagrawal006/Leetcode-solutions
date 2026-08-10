class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size() ; 
        int count = 0 ;

        for(string w : words){
            int m = w.size() ; 
            if(m>s.size()) continue; 

            bool flag = true ; //prefix
            for(int i = 0 ; i<m ; i++){
                if(w[i]!=s[i]){
                    flag =false; 
                    break ; 
                } 
            }
            if(flag){
                count++ ;  
                cout<<w << " "; 
            }
        }
        return count ; 
    }
};