class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0;
        int n=nums.size();
        
        int i=0;
        while(i<n){

            if(nums[i] == 0){

                int j=i;
                
                while(i<n && nums[i]==0) i++;

                int len = abs(i-j);
                long long subArrays = len*(len+1)/2;  // ways to find total subarray which can be formed from n length array
                ans += subArrays;

            }else{
                i++;
            }

        }

        return ans;  
    }
};