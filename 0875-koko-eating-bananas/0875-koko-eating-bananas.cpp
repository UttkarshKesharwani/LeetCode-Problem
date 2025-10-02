class Solution {
public:

    bool canEatWithSpeedK(int k,vector<int>& piles,int maxHours){
        int totalHours=0;
        for(int i=0;i<piles.size();i++){
            totalHours += ceil((double)piles[i]/k);  // ceil(x) Smallest integer ≥ x (round up)  eg-> ceil(2.1)=3 ceil(-2.7)=-2
            if (totalHours > maxHours) return false; 
        }
        return totalHours <= maxHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int lo=1;
        int hi=*max_element(begin(piles),end(piles));

        while(lo<hi){

            int mid = lo + (hi-lo)/2;

            if(canEatWithSpeedK(mid,piles,h)){
                hi = mid;
            }else{
                lo = mid+1;
            }

        }
        return hi; // u can also return lo in this template
    }
};