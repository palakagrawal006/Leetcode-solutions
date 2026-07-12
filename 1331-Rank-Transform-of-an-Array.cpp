class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size() ; 
        vector<int> arr2 = arr;
        sort(arr2.begin() , arr2.end()) ;

        unordered_map<int, int> s ;
        int i = 1 ;
        for(int x : arr2){
            if(s.find(x) == s.end()){
                s[x] = i;
                i++;
            }
        }

        for(int i = 0 ; i<n ; i++){
            arr[i] = s[arr[i]] ; 
        }
        return arr; 
    }
};