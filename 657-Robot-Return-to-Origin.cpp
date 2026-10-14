class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size() ; 

        int x = 0, y=0;

        for(int i = 0; i<n ; i++){
            if(moves[i] == 'U') x++;
            else if(moves[i] == 'D') x--;
            else if(moves[i] == 'L') y++;
            else  y--;
        }

          return (x==0) && (y==0);
    }
};
// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         int n = moves.size() ; 

//         int u =0 , d=0 , l=0, r=0 ;

//         for(int i = 0; i<n ; i++){
//             if(moves[i] == 'U') u++;
//             else if(moves[i] == 'D') d++;
//             else if(moves[i] == 'L') l++;
//             else  r++;
//         }

//           return (l == r) && (u == d);
//     }
// };