class Solution {
public:

    // [2,1,1,9];

    vector<int> dp;

    int ftd(vector<int>& nums,int i){

        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);

        if(dp[i]!=-1) return dp[i];

        return dp[i] = max( nums[i]+ftd(nums,i+2) , 0+ ftd(nums,i+1) );
    }

    // bottom up
    int fbu(vector<int>& nums){

        int n=nums.size();
        if(n==1) return nums[0];

        dp[n-1]=nums[n-1];
        dp[n-2] = max(nums[n-2],nums[n-1]);

        for(int i=n-3;i>=0;i--){
            dp[i] = max( nums[i]+dp[i+2] , 0+dp[i+1]);
        }

        return dp[0];
    }

    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        // int idx = 0; 
        // return ftd(nums,idx);
        return fbu(nums);
    }
};