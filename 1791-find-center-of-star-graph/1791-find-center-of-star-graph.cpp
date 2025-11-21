class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        // Pick any two edges , just make combined array from it and check if ele is coming twice then it means it have common ele 

        unordered_set<int> s;

        auto firstEdge = edges[0];
        auto secondEdge = edges[1];

        vector<int> arr ;

        for(int i=0;i<firstEdge.size();i++){
            arr.push_back(firstEdge[i]);
            arr.push_back(secondEdge[i]);
        }

        for(int i=0;i<arr.size();i++){
            if(s.count(arr[i])){
                return arr[i];
            }else{
                s.insert(arr[i]);
            }
        }

        return -1;
    }
};