class Solution {
public:
    int numRabbits(vector<int>& ans) {
       unordered_map <int, int> mp; 
       int sum = 0 ;
       for( int a : ans){
        mp[a+1]++;

        if(mp[a+1]== 1) sum+= a+1;
        if(mp[a+1]==a+1) mp[a+1] = 0; 
       }
       return sum ;
    }

};