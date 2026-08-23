class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size() ; 
        vector<int> ans; 
        unordered_map<int, int> mp ;
        for(int ele : digits){
            mp[ele]++;
        }

        for(int i= 100; i<=998 ; i+=2){
            int x = i ; 
            int a = x%10 ;  // ones place
            x = x/10 ;
            int b = x%10 ;  // tens place
            x = x/10 ;
            int c = x%10 ; //hundreds place

            if(mp[a]>0){ // exists
                mp[a]--;
                if(mp[b]>0){
                    mp[b]--;
                    if(mp[c]>0) ans.push_back(i) ; 
                    mp[b]++;
                }
                mp[a]++;
            }
        }
        return ans ; 
    }
};