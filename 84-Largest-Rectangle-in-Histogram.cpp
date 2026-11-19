class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n  = arr.size() ;

        // nsi 
        vector<int> nsi (n, n) ; //initially n value in each 
        // nsi[n-1] = n; 
        stack <int> st ;
        st.push(n-1);

        for(int i = n-2; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop() ;

            if(st.empty()) nsi[i] = n ;
            else nsi[i] = st.top()  ;
            cout<<nsi[i] <<" ";

            st.push(i);
        }
        cout<<endl; 

        // psi 
        vector<int> psi (n, -1) ; //initially -1 value in each 
        // psi[0] =-1; 
        stack <int> gt ;
        gt.push(0);

        for(int i = 1; i<n ; i++){
            while(!gt.empty() && arr[gt.top()] >= arr[i]) gt.pop() ;

            if(gt.empty()) psi[i] = -1 ;
            else psi[i] = gt.top()  ;
             cout<<psi[i] <<" ";

            gt.push(i);
        }


        // area
        int area = 0;
        int maxArea= INT_MIN ; 

        for(int i = 0 ; i<n ; i++){
            int width = nsi[i]-psi[i]- 1; 
            area = width * arr[i] ; 

            maxArea = max(maxArea, area) ;
        }
        return maxArea;
    }
};