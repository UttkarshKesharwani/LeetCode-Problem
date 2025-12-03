class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {

        vector<vector<string>> ans ; 
        unordered_map<string ,vector<string>> m;
        for(string str : arr){
            string lexo = str; 
            sort(lexo.begin(),lexo.end()); // taking eack string and sorting to its lexographicall order 
            if(m.find(lexo) == m.end()){  // now checking whether lexographical string is present in the map or not , if not 
                vector<string> v; // making the vector of string , and push the original string into it
                v.push_back(str);
                m[lexo]=v;  // and then map the lexographical string with vector of strings 
            }else{
                m[lexo].push_back(str);
            }
        } 
        // Travelling to map and putting all the values of map to the ans vector 
        for(auto x : m){
            vector<string> s = x.second;
            ans.push_back(s);
        }
        return ans ;
    }
};
