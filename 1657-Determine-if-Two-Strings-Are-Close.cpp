class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n!=m) return false; 
       
       unordered_map <char, int> m1;
       unordered_map <char, int> m2;
       unordered_map <int, int> mp1;
       unordered_map <int, int> mp2;

       for(char x : word1){
        m1[x]++;
       }
       for(char x : word2){
        if(m1.find(x) == m1.end()) return false; //if new letter in word2
        m2[x]++;
       }
       for(auto x : m1){
        mp1[x.second]++;
       }
       for(auto x : m2){
        mp2[x.second]++;
       }
       for(auto x : mp1){
        if(mp1[x.first]!=mp2[x.first])return false; 
       }
       return true; 
    }
}; 