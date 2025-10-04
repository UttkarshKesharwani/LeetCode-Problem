class Solution {
public:

    bool canReachWithinSpeed(vector<int>& dist,int mid , double hour){

        double totalTimeTakenSoFar = 0;  // time => dist/speed

        for(int i=0;i<dist.size()-1;i++){
            totalTimeTakenSoFar += ceil((double)dist[i] / mid);
        }
        
        // we are doing this because, the last train always get start with integer, and it is possible that when we divide the last train and without taking ceil of it may give the valid time  
        totalTimeTakenSoFar += (double)dist.back()/mid;

        return totalTimeTakenSoFar <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1;
        int hi = 10000000;

        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(canReachWithinSpeed(dist,mid,hour)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};