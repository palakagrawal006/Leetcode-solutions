class Solution {
public:
    vector<int> sumZero(int n) {
        // if(n== 1) return [0];

        vector<int> ans;
        int i = 1; 

        while(n>1){
            ans.push_back(i) ;
            ans.push_back(-i) ;
            n = n-2; 
            i++; 
        }
        if(n==1)  ans.push_back(0) ;
        return ans; 
    }
};