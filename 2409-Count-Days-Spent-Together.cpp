class Solution {
public:
    int getDate(string s){
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month = stoi(s.substr(0,2));
        int date = stoi(s.substr(3,2));

        int total = date ; 
        for(int i= 0 ; i<month-1; i++){
            total += days[i] ; 
        }
        return total; 
    }

    int countDaysTogether(string a1, string a2, string b1, string b2) {
       int start = max(getDate(a1), getDate(b1)) ; 
       int end = min(getDate(a2), getDate(b2)) ;

       if(end-start<0) return 0;
       return end-start+1;

    }
};