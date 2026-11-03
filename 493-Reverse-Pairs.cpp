class Solution {
public:
    int merge(vector<int>& nums , int l,int mid, int h){
        int i = l ; 
        int j = mid+1;

        int c = 0 ;

        // reverse
        while(i<=mid && j<=h){
            if((long long)nums[i]> (long long)2*nums[j]){
                c += (mid-i) +1;
                j++;
            }
            else i++;
        }

        i = l , j = mid+1;
        vector<int> t (h-l+1) ;
        int k = 0;

        while(i<=mid && j<=h){
            if(nums[i]<nums[j]) t[k++] = nums[i++] ;
            else t[k++] = nums[j++] ; 
        }

        while(i<=mid) t[k++] = nums[i++] ;
        while(j<=h) t[k++] = nums[j++] ; 


        for(int i = 0 ; i<t.size() ; i++){
            nums[l+i] =  t[i] ;
        }

        return c; 
    }
    void mergesort(vector<int>& nums , int &c, int l, int h){
        if(l==h) return ;

        int mid = (h+l)/2;

        mergesort(nums, c, l , mid);
        mergesort(nums, c, mid+1, h);

        c = c+ merge(nums , l, mid, h) ; 

    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size() ; 
        int c = 0 ;

        mergesort(nums , c, 0  , n-1) ; 
        return c; 



        // // brute force = TC - O(n^2)
        // for(int i = 0 ; i<n-1 ; i++){
        //     for(int j = i+1 ; j<n; j++){
        //         if(nums[i]>2*nums[j]) c++;
        //     }
        // }
        // return c ; 
    }
};