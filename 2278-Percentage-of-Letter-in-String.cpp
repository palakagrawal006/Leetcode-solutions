class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size() ; 
        int count = 0 ; 

        for(char c : s){
            if(c==letter)count++ ; 
        }
     
        int ans = (count*100)/n ; 
        return ans;
    }
};