class Solution {
public:

    // [2,1,1,9];
    
    vector<int> dp;

    int f(vector<int>& nums,int i){

        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);

        if(dp[i]!=-1) return dp[i];

        return dp[i] = max( nums[i]+f(nums,i+2) , f(nums,i+1) );
    }

    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        int idx = 0; 
        return f(nums,idx);
    }
};