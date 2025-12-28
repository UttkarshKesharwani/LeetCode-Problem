class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<long long> pref(n);

        if(k==0) return nums;
        if(n<2*k+1) return ans;


        pref[0] = nums[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }

        for(int i=k;i<=n-k-1;i++){
            int leftIdx = i-k;
            int rightIdx = i+k;
            long long sum = leftIdx == 0 ? pref[rightIdx] :  pref[rightIdx] - pref[leftIdx-1] ;
            int avg = sum / (2*k+1);
            ans[i] = avg;
        }


        return ans;
    }
};