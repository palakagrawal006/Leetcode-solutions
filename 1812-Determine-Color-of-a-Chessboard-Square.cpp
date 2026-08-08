class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0]-'a'+1;
        int row = coordinates[1];
    

        if((row%2 != 0) && (col%2 !=0))  return false; 
        else if(row%2 != 0 && col%2 ==0) return true; 
        else if(row%2 == 0 && col%2 ==0) return false;
        return true;  
    }
};