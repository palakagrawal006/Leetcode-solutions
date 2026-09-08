class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size() ;
         int ans= 0; 
        vector<vector<int>> dp(n , vector<int>(n, 0));

        for(int k = 0; k<n; k++){
            int i =0, j =k; 
            while(i<n && j<n && i<=j){
                // single length
                if(i==j){
                    dp[i][j] = 1;
                    ans++;
                }
                 
                //  2 length
                else if(j==i+1 && s[i]==s[j]) {
                    dp[i][j] = 1;
                    ans++;
                }

                // 3 or more length
                else if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    ans++;
                }
                
                // else remain 0 ; 
                i++;
                j++;
            }
        }
        return ans; 
        
    }
};