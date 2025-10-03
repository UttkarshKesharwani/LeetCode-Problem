class Solution {
public:
    bool canBeShipped(vector<int>& weights,int mid, int days){

        int weightSoFar = 0;
        int daysUsed = 1;
        
        for(int i=0;i<weights.size();i++){
            
            if (weights[i] > mid) return false; // cannot ship if any package > capacity

            if(weightSoFar + weights[i] > mid){
                daysUsed++;
                weightSoFar=0; // for the remaining weights
            }
            weightSoFar += weights[i];
        }

        return daysUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int sum=0;
        int maxEle = INT_MIN;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>maxEle){
                maxEle = weights[i];
            }
            sum+=weights[i];
        }


        int lo =  maxEle;
        int hi =  sum;

        while(lo<hi){
            
            int mid = lo + (hi-lo)/2;

            cout<<mid<<"->"<<canBeShipped(weights,mid,days)<<" ";
            
            if(canBeShipped(weights,mid,days)){
                hi = mid;  
            }else{
                lo = mid+1;
            }
        }

        return lo;
    }
};