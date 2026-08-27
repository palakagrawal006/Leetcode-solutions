class Solution {
public:
    string reorganizeString(string s) {
        unordered_map <char, int> mp ; 

        for(char c : s){
            mp[c]++;
        }

        string t = "" ; 
        priority_queue<pair<int , char>> pq ; //max heap 

        for(auto ele : mp){
            pq.push({ele.second , ele.first}) ; // freq, char 
        }

        pair <int, char> prev = {0 , '#'};

        while(!pq.empty()){
            auto [f, c] = pq.top() ; 
            pq.pop() ;  

            t.push_back(c);
            f--; 

            if(prev.first>0) pq.push(prev) ; // not current - previous  
            prev ={f , c} ;
        }

        if (prev.first > 0) return "";

        for(int i =1; i<t.size() ; i++){
            if(t[i] == t[i-1]) return "" ; 
        }
        return t; 
    }
};