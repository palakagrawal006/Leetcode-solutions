class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(); 

        vector<int> pos;
        vector<int> neg ;

        for(int x : nums){
            if(x>=0) pos.push_back(x);
            else neg.push_back(x) ; 
        }

        int i = 0, j =0 ;
        nums.clear() ; 

        while(i<pos.size() && j<neg.size()){
            nums.push_back(pos[i]) ; 
            nums.push_back(neg[j]); 
            i++;
            j++;  
        }

        return nums;
    }
};