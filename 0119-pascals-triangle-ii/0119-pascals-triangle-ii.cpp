class Solution {
public:
    vector<vector<int>> buildPascalTriangle(int totalRows){
        
        vector<vector<int>> ans(totalRows);
        
        for(int i=0;i<totalRows;i++){

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

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans =  buildPascalTriangle(rowIndex+1);
        return ans.back();
    }
};