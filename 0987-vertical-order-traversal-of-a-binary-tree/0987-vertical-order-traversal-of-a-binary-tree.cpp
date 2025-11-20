
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        
        unordered_map<int,vector<int>> mp;  // <col,vector of nodes>
        queue<pair<TreeNode* , pair<int,int>>> q; // <node,<row,col>>

        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        q.push({root,{0,0}});

        while(!q.empty()){

            int n = q.size();
            unordered_map<int,vector<int>> tempMap; // for each level , if there are multiple element present in the same col then sort the vector

            for(int i=0;i<n;i++){

                auto [currNode,dist] = q.front();
                q.pop();

                int row = dist.first;
                int col = dist.second;

                minCol = min(minCol,col);
                maxCol = max(maxCol,col);
                tempMap[col].push_back(currNode->val);


                if(currNode->left) q.push({ currNode->left, {row+1,col-1} });
                if(currNode->right) q.push({ currNode->right, {row+1,col+1} });
            }

            // sort the vector of tempMap
            for(auto &ele : tempMap){
                sort(ele.second.begin(),ele.second.end());
            }

            // insert into map mp
            for(auto &ele : tempMap){
                for(auto val : ele.second){
                    mp[ele.first].push_back(val);
                }
            }

        }
 
        for(int col=minCol ; col<=maxCol ; col++){
            vector<int> temp = mp[col];
            ans.push_back(temp);
        }

        return ans;
    }
};