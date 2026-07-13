class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector <int> ans ; 
        string base = "123456789" ;


        for(int i = 2 ; i<= 9 ; i++){ // window size
            for(int j = 0 ; i+j<=9; j++){ ///index
                int x = stoi(base.substr(j , i));

                if(x >= low && x<=high) ans.push_back(x);
            }
        }
        sort(ans.begin() , ans.end()) ; 
        return ans; 
    }
};