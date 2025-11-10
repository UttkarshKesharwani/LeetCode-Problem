class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& interval){
        vector<vector<int>> ans;

        ans.push_back(interval[0]);

        for(auto ele:interval){
            if(ans.back()[1]>=ele[0]){
                ans.back()[1] = max(ans.back()[1],ele[1]);
            }else{
                ans.push_back(ele);
            }
        }


        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;

        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }

        int i=0;
        int n=intervals.size();

        while(i<n && intervals[i][0] <= newInterval[0] ){
            ans.push_back(intervals[i]);
            i++;
        }

        ans.push_back(newInterval);

        while(i<n) {
            ans.push_back(intervals[i]);
            i++;
        }

        for(auto ele:ans){
            cout<<ele[0]<<" "<<ele[1]<<endl;
        }

        return mergeIntervals(ans);

    }
};