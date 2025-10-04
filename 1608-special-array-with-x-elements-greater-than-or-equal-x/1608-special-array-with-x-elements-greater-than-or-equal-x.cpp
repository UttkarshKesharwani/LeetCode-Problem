class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int ans=0;
        for(int i=0;i<1000;i++){
            int count = 0; // counting For Each Number
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=i){
                    count++;
                }
            }
            if(count == i) return i;
        }

        return -1;
    }
};