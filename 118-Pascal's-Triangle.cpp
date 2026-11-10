class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v ; 

        for(int i = 0 ; i<numRows ; i++){
            vector<int> s (i+1) ; 
            v.push_back(s) ; 
        }

        for(int i = 0 ; i<numRows ; i++){
            int size = v[i].size() ; 

            for(int j =0 ; j<size; j++){
                if(j==0 || j==size-1) v[i][j] = 1; 
                else v[i][j] = v[i-1][j] + v[i-1][j-1] ;
            }
        }
        return v; 
    }
};