class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        unordered_set<int> visited;
        queue<int> q;

        q.push(0);
        visited.insert(0);

        while(not q.empty()){
            int curr = q.front();
            q.pop();
            for(int &neigh : rooms[curr]){
                if(not visited.count(neigh)){
                    q.push(neigh);
                    visited.insert(neigh);
                }
            }
        }

        return visited.size() == rooms.size(); // if the set has the size of the rooms means we visited all the rooms
    } 
};