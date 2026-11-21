class MyQueue {
public:
    stack<int> s1 ;  
    stack<int> s2 ; 
    int size  ;
    MyQueue() {
        size = 0 ;
    }
    
    void push(int x) {
        if(size == 0) {
            size++;
            s1.push(x) ; 
            return ;
        }

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop(); 
         }
        s1.push(x) ; 

        while(!s2.empty()){
            s1.push(s2.top()); 
            s2.pop();
        }
        size++;
    }
    
    int pop() {
        if(size == 0) return -1; 
        int x = s1.top() ; 
        s1.pop() ; 
        return x ; 
    }
    
    int peek() {
       if(size == 0) return -1; 
        int x = s1.top() ;
        return x ; 
    }
    
    bool empty() {
        return s1.empty() ; 
    }
};

