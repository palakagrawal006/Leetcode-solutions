class Solution {
public:
    int maxProduct(int n) {
        vector <int> v ; 

        while(n>0){
            int dig = n%10 ;
            n = n/10; 
            v.push_back(dig) ;
        }
        sort(v.begin() , v.end()) ; 
        
        int prod = v[v.size()-1] * v[v.size()-2];
        return prod; 
    }
};