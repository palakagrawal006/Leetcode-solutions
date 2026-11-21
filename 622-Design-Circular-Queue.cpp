class MyCircularQueue {
public:
    vector<int> q ; 
    int size, s; 
    int f , b;
    MyCircularQueue(int k) {
        vector<int> v(k) ; 
        q = v;
        size= k; 
        s = 0; 
        f = 0 ;
        b = 0 ; 
    }
    
    bool enQueue(int value) {
        if(s == size) return false; 
        q[b] = value ;
        b++; 
        s++;
        if(b==size) b = 0 ; 
        return true;  
    }
    
    bool deQueue() {
        if(s==0 ) return false; 
        f++;
        if(f == size) f= 0 ;
        s--;
        return true; 
    }
    
    int Front() {
        if(s == 0) return -1; 
        return q[f] ; 
    }
    
    int Rear() {
        if(s==0)return -1;
        if(b == 0) return q[size-1] ; 
        return q[b-1]; 
    }
    
    bool isEmpty() {
        return (s==0) ; 
    }
    
    bool isFull() {
        return (s==size) ;
    }
};


// // Use of built-in std::queue is strictly prohibited by the restrictions.
// class MyCircularQueue {
// public:
//     queue<int> q ; 
//     int size; 
//     int s ;
//     MyCircularQueue(int k) {
//         size= k; 
//         s = 0; 
//     }
    
//     bool enQueue(int value) {
//         if(s == size) return false; 
//         q.push(value) ; 
//         s++;
//         return true;  
//     }
    
//     bool deQueue() {
//         if(s==0 ) return false; 
//         q.pop() ;
//         s--;
//         return true; 
//     }
    
//     int Front() {
//         if(s == 0) return -1; 
//         return q.front() ; 
//     }
    
//     int Rear() {
//         if(s==0)return -1;
//         return q.back() ; 
//     }
    
//     bool isEmpty() {
//         return (s==0) ; 
//     }
    
//     bool isFull() {
//         return (s==size) ;
//     }
// };

