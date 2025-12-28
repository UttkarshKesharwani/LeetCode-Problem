class Solution {
public:

    int findFirstNegativeIdx(vector<int>& arr){
        int lo=0,hi=arr.size()-1;
        int negativeIdx = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]<0){
                negativeIdx = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return negativeIdx;
    }

    int countNegatives(vector<vector<int>>& grid) {

        int n=grid.size();
        int count = 0;

        for(int i=0;i<n;i++){
            int firstNegIdx = findFirstNegativeIdx(grid[i]);
            if(firstNegIdx != -1){
                count += n-firstNegIdx; 
            }
        }

        return count;
    }
};