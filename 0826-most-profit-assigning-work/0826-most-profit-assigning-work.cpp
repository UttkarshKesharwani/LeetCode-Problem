class Solution {
public:
    int findJobAndDo(int workerAbility , vector<pair<int,int>>& arr){
        
        int lo = 0;
        int hi = arr.size()-1;

        int money = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(workerAbility < arr[mid].first){
                hi = mid - 1;
            }else{
                ans = arr[mid].second;
                lo = mid + 1;
            }
        }

        // if(lo == 0) return 0; // no job can be done
        // return arr[hi].second;

        return money;  // also can send this
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> arr;

        for(int i = 0; i < profit.size(); i++){
            arr.push_back({difficulty[i], profit[i]});
        }      

        sort(arr.begin(), arr.end());

        int maxSeenSoFar = 0;
        for(int i = 0; i < arr.size(); i++){
            maxSeenSoFar = max(maxSeenSoFar, arr[i].second);
            arr[i].second = maxSeenSoFar;
        }

        int ans = 0;
        for(int i = 0; i < worker.size(); i++){
            ans += findJobAndDo(worker[i], arr);
        }

        return ans;
    }
};
