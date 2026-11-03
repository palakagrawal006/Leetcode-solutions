class Solution {
public:
    void helper(string str, int k, string &ans){
        int n = str.size() ;

        // base case 
        if(n==0) return ; 

        // factorial of (n-1)
        int fact = 1;
        for(int i=2; i<n; i++){
            fact = fact*i;
        }

        // index for char 
        int idx = k/fact ; 
        if(k%fact ==0) idx--;

        // add ans  , update str 
        char c = str[idx] ; 
        ans += c ;
        string rem = str.substr(0, idx) + str.substr(idx+1) ; 
        str = rem ; 


        // update k 
        int q = k%fact ; 
        if(q == 0) q = fact ; 

         helper(str, q, ans) ; 

    }
    string getPermutation(int n, int k) {
        string str = "" ;

        for(int i =1; i<=n; i++){
            str += to_string(i);
        }

        string ans =""; 
        helper(str, k, ans) ; 

        return ans ; 
    }
};
