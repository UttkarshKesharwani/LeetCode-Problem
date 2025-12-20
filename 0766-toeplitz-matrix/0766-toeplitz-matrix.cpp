class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        // check other solution

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i-1<0 || j-1<0 || i-1>=rows || j-1>=cols) continue;  // out of bond access
                // if we check top-left neighbour for each element and it must be same 
                if(matrix[i][j] !=  matrix[i-1][j-1]) return false;  
            }
        }

        return true;

    }   
};