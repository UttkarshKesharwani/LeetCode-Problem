class Solution {
public:
    bool canWeMakeMBouqets(vector<int>& bloomDay, int m, int k,int mid){
        int bouquetsMadeSoFar = 0;
        int flowerCount = 0;
        for(int i=0;i<bloomDay.size();i++){
            
            if(mid>=bloomDay[i]){
                flowerCount++;
                if(flowerCount == k){
                    bouquetsMadeSoFar++;
                    flowerCount = 0;
                }
            }else{
                flowerCount=0;
            }
        }

        return bouquetsMadeSoFar >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        auto  [min,max] = minmax_element(bloomDay.begin(),bloomDay.end());   

        int lo = *min;
        int hi = *max;

        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(canWeMakeMBouqets(bloomDay,m,k,mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};