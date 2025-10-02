class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        int num = 1,i=0;
        while(i<n && k>0){
            if(arr[i]==num){
                i++;
            }else{
                k--;
            }
            num++;
        } 

        if(k!=0){
            while(k--) num++;
        }


        return num-1;  
    }
};