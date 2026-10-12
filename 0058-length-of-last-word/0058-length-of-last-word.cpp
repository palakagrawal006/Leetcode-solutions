class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp ; 
        stringstream ss(s);
        while(ss >> temp){
           continue;
        }

        return temp.size() ;
        // return 0 ;
    }
};