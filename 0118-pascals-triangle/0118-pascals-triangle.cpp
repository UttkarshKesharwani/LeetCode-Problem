class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int i=0;i<numRows;i++){

            vector<int>temp (i+1,1);

            if(i+1>2){
                for(int j=1;j<=i-1;j++){
                    temp[j] = ans[i-1][j] + ans[i-1][j-1];
                }
            }
            ans[i] = temp;

        }

        return ans;
    }
};