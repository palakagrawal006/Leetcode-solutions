class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size() ; 

        queue <int> r ;
        queue <int> d ;

        for(int i = 0 ; i<n ; i++){
            if(senate[i]=='R') r.push(i) ;
            else d.push(i) ;
        }

        while(!r.empty() && !d.empty()){
            int r_idx = r.front() ;
            int d_idx = d.front() ; 
            d.pop() ;
            r.pop() ;

            if(r_idx < d_idx) r.push(r_idx +n) ; 
            else d.push(d_idx +n) ; 
        }
        if(r.empty()) return "Dire" ; 
        return "Radiant" ;
    }
};