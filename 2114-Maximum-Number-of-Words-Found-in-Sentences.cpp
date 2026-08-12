class Solution {
public:
    int mostWordsFound(vector<string>& sent) {
        int n = sent.size() ; 
        
        int maxi = 0 ; 

        for(string s : sent){
            int count = 0 ;

            string temp ; 
            stringstream ss(s) ; 

            while(ss >> temp){
                count++ ; 
            }
            maxi = max(maxi , count) ; 
        }

        return maxi  ;
    }
};