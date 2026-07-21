class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n =s.size() ; 

        // existing count of 1's
        int actives = count(s.begin() , s.end() , '1'); 

        vector <int> inactives ; //zero block 
         
        int i = 0 ; 
        while(i<n){
            if(s[i]=='0'){
                int start = i ; 
                while(i<n && s[i]=='0') i++;

                inactives.push_back(i-start);
            }
            else  i++;
        }

        int maxPairSum = 0 ;
        for(int i = 1 ; i<inactives.size(); i++ ){
            maxPairSum = max(maxPairSum , inactives[i]+inactives[i-1]); 
        }

        return maxPairSum+actives ; 

    }
};