class Solution {
public:

    int findMaxBeautyWithinPrice(vector<vector<int>>& items, vector<int>& queries, int price) {

        int n = items.size();
        int maxBeautySoFar = 0;
        int lo = 0;                      
        int hi = n - 1;                 

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;   

            if (items[mid][0] <= price) {   // ✅ correct comparison direction
                maxBeautySoFar = max(maxBeautySoFar, items[mid][1]); // ✅ keep max beauty
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return maxBeautySoFar;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        vector<int> ans;

        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        for (int i = 0; i < queries.size(); i++) {
            int result = findMaxBeautyWithinPrice(items, queries, queries[i]);
            ans.push_back(result);
        }

        return ans;
    }
};
