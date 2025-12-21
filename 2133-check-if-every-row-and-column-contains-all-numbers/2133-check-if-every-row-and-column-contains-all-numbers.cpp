class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        // for each row
        for(int i=0;i<rows;i++){
            unordered_set<int> s;
            for(int j=0;j<cols;j++){
                s.insert(matrix[i][j]);
            }
            if(s.size() != rows) return false;  // if each row or col contains all integer then the size must be equals to n
        }

        // for each col
        for(int i=0;i<rows;i++){
            unordered_set<int> s;
            for(int j=0;j<cols;j++){
                s.insert(matrix[j][i]);
            }
            if(s.size() != rows) return false;
        }

        return true;

    }
};