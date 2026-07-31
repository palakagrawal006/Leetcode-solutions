class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size() ; 

        map <char, int> mp;

        for(int x : s){
            mp[x]++;
        }

        string first = "" ; 
        string mid = "" ; 

        for(auto ele : mp){
            for(int i = 0 ; i<ele.second/2 ; i++){
                first.push_back(ele.first) ; 
            }

            if(ele.second%2 != 0 ){
                mid.push_back(ele.first) ; 
            }
        }

        string second = first;
        reverse(second.begin() , second.end()) ; 

        return first + mid + second; 
    }
};