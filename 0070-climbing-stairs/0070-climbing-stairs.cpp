class Solution {
public: 
    vector<int> dp;

    int climbingStairs(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;  // base case: one valid way to stay at step 0
        if(dp[n] != -1) return dp[n];

        int oneStep = climbingStairs(n - 1);
        int twoStep = climbingStairs(n - 2);

        return dp[n] = oneStep + twoStep;
    }

    int climbStairs(int n) {
        dp.resize(n + 1, -1);  //  initialize with -1 for memoization
        return climbingStairs(n);
    }
};
