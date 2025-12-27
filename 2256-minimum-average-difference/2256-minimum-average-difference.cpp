class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return 0;

        int minIdx = -1;
        long long minDiff = LLONG_MAX;
        
        vector<long long> pref(n),suff(n);

        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+nums[i];
        }

        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]+nums[i];
        }

        for(int i=0;i<n;i++){

            long long prefSum = pref[i];
            long long suffSum = (i==n-1) ? 0 : suff[i+1];

            long long leftAvg = prefSum / (i+1);
            long long rightAvg = (i==n-1) ? 0 : suffSum / (n-i-1); 

            long long diff = llabs(leftAvg-rightAvg);

            if(diff<minDiff){
                minDiff = diff;
                minIdx = i;
            }
        }

        return minIdx;
    }
};