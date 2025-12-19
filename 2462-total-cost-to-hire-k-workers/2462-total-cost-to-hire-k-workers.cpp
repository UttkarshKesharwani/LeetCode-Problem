class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        long long ans = 0;
        int n = costs.size();

        // pq1 -> for first set of candidate from starting of array
        // pq2 -> for second set of candidate from last of array 
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int i = 0, j = n - 1;
        int temp = candidates;

        while (temp-- && i <= j) {
            pq1.push(costs[i++]);
        }

        temp = candidates;
        while (temp-- && i <= j) {
            pq2.push(costs[j--]);
        }

        while (k--) {

            int x = pq1.empty() ? INT_MAX : pq1.top();
            int y = pq2.empty() ? INT_MAX : pq2.top();

            if (x <= y) {

                ans += x;   // if tie, take from first set
                pq1.pop();
                if (i <= j) pq1.push(costs[i++]);

            } else {

                ans += y;
                pq2.pop();
                if (i <= j) pq2.push(costs[j--]);
            }
        }

        return ans;
    }
};
