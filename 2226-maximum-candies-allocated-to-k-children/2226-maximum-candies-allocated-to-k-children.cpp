class Solution {
public:
    // try to giving equal candies to each children (which is mid here)
    bool isPossibleToAllocateEqualCandies(vector<int>& candies, long long k,int mid){

        long long count = 0; // will keep track of how many children get equal candies

        for(auto candy:candies){
            int childCanGetEqualCand = candy/mid; // how many chidren can get equal candy from piles
            count += childCanGetEqualCand;
            if(count>=k) return true; 
        }
        
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {  // case [5,13,3], k=3

        int maxCand = *max_element(candies.begin(),candies.end());

        int lo=1;
        int hi=maxCand;
        int result = 0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isPossibleToAllocateEqualCandies(candies,k,mid)){
                result = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return result;
    }
};