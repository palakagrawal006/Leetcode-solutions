class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // we have to find nse , then subtract nse with price
        // nse = backward
        int n = prices.size() ;
        stack<int> st; 
        // prices[n-1] = prices[n-1]-0 ;  // no need to write already understandable; 

        // st.push(prices[n-1]) ; 

        for(int i = n-1; i>=0; i--){
            int x = prices[i] ; 

            while(!st.empty() && st.top()>x) st.pop() ;
            
           
            if(!st.empty()) prices[i] = x-st.top() ; 
            // if empty = prices[i] = x-0; 

            st.push(x) ; 
        }

        return prices;
    }
};