class Solution {
public:
    string lcs(string s1, string s2) {
       int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // 0 for base case

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1],  dp[i - 1][j]);
            }
        }
        // print
        string s = "" ;
        int i = n , j = m ;
        while(i>0 && j>0){
             if(s1[i-1]==s2[j-1]){
               s+=s1[i-1] ;  
               i--;
               j--;
            } 
            else if(dp[i][j - 1] >  dp[i - 1][j] )j--;
            else i--;  
        }
        reverse(s.begin(), s.end()) ; 
        return s; 
    }
    string shortestCommonSupersequence(string s1, string s2) {
        string l =  lcs(s1,s2);
        // int len = s1.size() +s2.size() - l.size(); 
        cout<<l ;

        int i=0 , j=0 , k = 0; 
        string ans = "" ; 

        while(i<s1.size() && j<s2.size() && k<l.size()){
            while(i<s1.size() && s1[i]!=l[k]){
                ans += s1[i] ; 
                i++;
            }
            while(j<s2.size() && s2[j]!=l[k]){
                ans += s2[j] ; 
                j++;
            }
            if(i<s1.size() && j<s2.size() && k<l.size()) ans+= l[k] ; 
            i++;
            j++;
            k++;
        }
        while(i<s1.size()){
            ans += s1[i] ; 
            i++;
        }
        while(j<s2.size() ){
            ans += s2[j] ; 
            j++;
        }
        return ans ; 
     }
};