//Heap - min heap + max heap 
class MedianFinder {
public:
    priority_queue<int> left; // maxHeap
    priority_queue<int , vector<int>, greater<int>> right;// minheap
    int n  ;
    int k;
    MedianFinder() {
       
    }

    void addNum(int num) {
       if(left.size()==0  || left.top()>num ) left.push(num) ; 
       else right.push(num); 
 
        if(left.size()>right.size()+1){
            right.push(left.top()) ; 
            left.pop() ; 
        }
        if(right.size()>left.size()+1){
            left.push(right.top()) ; 
            right.pop() ; 
        }
    }

    double findMedian() {
        if(right.size()== left.size()) return (left.top() + right.top())/2.0 ; 
        // even 
        else if(right.size()>left.size()) return right.top() ;
        else return left.top() ; 
    }
};


// // insertion sort - doesnt need to sort whole array always
// // still TLE 
// class MedianFinder {
// public:
//     vector<int> v;
//     MedianFinder() {
//         v = vector<int>() ; 
//     }

//     void addNum(int num) {
//         v.push_back(num);
//         int i = v.size()-1 ; //pushed ele
        
//         while(i>=1 && v[i]< v[i-1]) {
//             swap(v[i],  v[i-1]) ;
//             i--;
//         } 

//     }

//     double findMedian() {
//         int n = v.size() ; 
//         if(n%2 != 0)
//             return v[n/2] ; 
//         else 
//             return ( v[n/2]+v[(n/2)-1]) / 2.0 ; 
//     }
// };


// //TLE  -- Every ele needs sort- o(nlogn)  
// class MedianFinder {
// public:
//     vector<int> v;
//     MedianFinder() {
//         v = vector<int>() ; 
//     }

//     void addNum(int num) {
//         v.push_back(num);
//         sort(v.begin(), v.end()) ;  
//     }

//     double findMedian() {
//         int n = v.size() ; 
//         if(n%2 != 0)
//             return v[n/2] ; 
//         else 
//             return ( v[n/2]+v[(n/2)-1]) / 2.0 ; 
//     }
// };
