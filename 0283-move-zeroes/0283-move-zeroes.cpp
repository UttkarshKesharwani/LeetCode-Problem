class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n=nums.size();
        queue<int> q;  // we take queue cuz we need to maintain the relative order
        int zeroCount = 0;

        for(auto &ele:nums){
            if(ele!=0) q.push(ele);
            else zeroCount++;
        }

        for(int i=0;i<n;i++){
            if(not q.empty()){
                nums[i] = q.front();
                q.pop();
            }else{
                nums[i] = 0;
            }
        }

    }
};