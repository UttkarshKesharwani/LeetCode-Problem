class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        // do also check the next submission

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,0));

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        // we do reverse enginnering here
        // we need the front element and then we need to pop the front element which take linear time 
        for(auto &ele:mp){
            if(ele.first>=0){
                sort(ele.second.begin(),ele.second.end());
            }else{
                sort(ele.second.rbegin(),ele.second.rend());
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return ans;
    }
};