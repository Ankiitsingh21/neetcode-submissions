class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,high=arr.size()-k;
        int mid=0;
        while(low<high){
            mid=low+(high-low)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return vector<int>(arr.begin()+low,arr.begin()+low+k);
    }
};