class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "" ;

        for(int i = 0; i<min(n,m) ; i++){
            ans+= word1[i]; 
            ans+= word2[i]; 
        }
        if(m>n){
            word2 = word2.substr(n);
            ans+=word2;
        }
        else {
            word1 = word1.substr(m);
            ans+=word1;
        }
        return ans;
    }
};