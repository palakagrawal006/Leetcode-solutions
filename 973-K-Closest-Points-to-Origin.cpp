class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        int n = arr.size() ; 

        priority_queue <pair<double, vector<int>>> pq; //max heap

        for(int i = 0; i<n; i++){
            int x = arr[i][0];
            int y = arr[i][1];

            double dis = sqrt(x*x + y*y) ; 
            cout<< x << " " <<y << " "<< dis <<endl ;

            pq.push({dis, {x, y}}) ;

            if(pq.size()==k+1){
                pq.pop(); 
            }
        }

        vector<vector<int>> ans ;
        while(!pq.empty()){
            ans.push_back(pq.top().second); 
            pq.pop() ; 
        }
        return ans; 

    }
};
