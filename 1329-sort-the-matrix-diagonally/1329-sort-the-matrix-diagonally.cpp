class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,0));
        
        // mp[key] = { vector_of_values, index_pointer }
        unordered_map< int, pair<vector<int>,int> > mp;  

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int key = i-j;
                mp[key].first.push_back(mat[i][j]);
                mp[key].second = 0;
            }
        }

        for(auto &ele : mp){
            sort(ele.second.first.begin(),ele.second.first.end());
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int key = i-j;
                int idx = mp[key].second;
                ans[i][j] = mp[key].first[idx];
                mp[key].second++;
            }
        }

        return ans;   
    }
};