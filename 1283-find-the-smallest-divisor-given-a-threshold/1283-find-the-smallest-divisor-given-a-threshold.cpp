class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        // Brute force :- we can check for every divisor starting from 1

        int n=*max_element(nums.begin(),nums.end());

        cout<<"n"<<n<<endl;

        for(int i=1;i<=n;i++){
            int sum = 0;
            for(int j=0;j<nums.size();j++){
                sum += ceil((double)nums[j]/i);
            }
            if(sum<=threshold){
                return i;
            }
        }

        return -1;
    }
};