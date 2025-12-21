class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        unordered_set<int> st;
        for(int i=1;i<=rows;i++) st.insert(i);  

        for(int i=0;i<rows;i++){
            unordered_set<int> s(st.begin(),st.end());
            for(int j=0;j<cols;j++){
                int ele = matrix[i][j];
                if(s.count(ele)) s.erase(ele);  // if already present remove from set s, so that it will never come again
                else return false; // means not found
            }
        }

        for(int i=0;i<rows;i++){
            unordered_set<int> s(st.begin(),st.end());
            for(int j=0;j<cols;j++){
                int ele = matrix[j][i];
                if(s.count(ele)) s.erase(ele);
                else return false;
            }
        }

        return true;
    }
};