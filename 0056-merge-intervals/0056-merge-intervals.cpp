class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end()); // sort by start time

        int i = 0;
        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;
            // keep merging while next interval overlaps
            while (j < n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);
                j++;
            }

            ans.push_back({start, end});
            i = j; // move to the next unmerged interval
        }

        return ans;
    }
};
