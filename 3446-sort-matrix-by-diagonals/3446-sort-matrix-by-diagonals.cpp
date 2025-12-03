class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,0));

        // mp[key] = { vector_of_values, index_pointer }
        unordered_map< int, pair<vector<int>,int> > mp;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int key = i-j;
                mp[key].first.push_back(grid[i][j]);
                mp[key].second = 0;
            }
        }

        for(auto &ele:mp){
            if(ele.first>=0){
                sort(ele.second.first.rbegin(),ele.second.first.rend());
            }else{
                sort(ele.second.first.begin(),ele.second.first.end());
            }
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