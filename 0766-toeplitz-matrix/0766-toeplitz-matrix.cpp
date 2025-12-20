class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        unordered_map<int,int> mp; // <(i-j),ele> 
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int j=0;j<cols;j++){
            int key = 0-j;
            mp[key] = matrix[0][j];
        }

        for(int i=1;i<rows;i++){
            int key = i-0;
            mp[key] = matrix[i][0];
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int key = i-j;
                if(matrix[i][j] != mp[key]) return false;
            }
        }

        return true;

    }   
};