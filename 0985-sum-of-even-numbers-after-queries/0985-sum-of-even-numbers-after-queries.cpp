class Solution {
public:
    
    int findSum(vector<int>& nums){
        int count = 0;
        for(int &ele : nums){
            if(ele % 2 == 0) count += ele;
        }
        return count;
    }

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> ans;
        for(auto &v : queries){
            int ele = v[0];
            int idx = v[1];
            nums[idx] += ele;                 
            ans.push_back(findSum(nums)); 
        }

        return ans;
    }
};
