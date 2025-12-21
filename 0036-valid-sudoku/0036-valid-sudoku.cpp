class Solution {
public:
    bool isValidSubBox(int sr, int er, int sc, int ec,vector<vector<char>>& board){

        unordered_set<char> s;

        for(int i=sr;i<er;i++){
            for(int j=sc;j<ec;j++){
                if(board[i][j] == '.') continue;
                if(s.find(board[i][j]) != s.end()) return false;
                s.insert(board[i][j]);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        // validate each row
        for(int row = 0; row < 9; row++){
            unordered_set<char> s;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.') continue;
                if(s.find(board[row][col]) != s.end())
                    return false;
                s.insert(board[row][col]);
            }
        }

        // validate each column
        for(int col = 0; col < 9; col++){
            unordered_set<char> s;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.') continue;
                if(s.find(board[row][col]) != s.end())
                    return false;
                s.insert(board[row][col]);
            }
        }

        // validate each sub-grid(total->9) box 

        int sr=0,er=3;  // startRow,endRow
        int sc=0,ec=3;  // startCol,endCol

        for(int box=1;box<=9;box++){

            if(not isValidSubBox(sr,er,sc,ec,board)) return false;

            // move to next box
            sc+=3;
            ec+=3;

            if(sc==9){
                sr+=3;
                er+=3;
                sc=0;
                ec=3;
            }
        }
        
        return true;
    }
};
