class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string , int> mp ; 
     
        for(int i = 0; i<list1.size() ; i++){
            mp[list1[i]]= i;
        } 
     
        int mini = INT_MAX ; 
        int sum = 0;
        vector <string> ans;

        for(int i = 0 ;i<list2.size(); i++){
            string ele = list2[i] ;
            if(mp.find(ele) != mp.end()){
                sum= i+ mp[ele] ;

                if(sum < mini){
                    mini = sum  ;
                    ans.clear() ; 
                    ans.push_back(ele) ; 
                } 
                else if(sum == mini){
                    ans.push_back(ele) ;
                }
            }
        }
        return ans ;

    }
};