class Solution {
public:
    string frequencySort(string s) {

        vector<pair<int,char>> character(62, {0,'a'});  // a-z -> 0 to 25 , A-Z -> 26 to 51 , 0-9 -> 48 to 57
        string str = "";

        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){ 
                int idx = s[i] - 'a';       
                character[idx].first++;    
                character[idx].second = s[i];
            } 
            else if(s[i]>='A' && s[i]<='Z'){ 
                int idx = 26 + (s[i] - 'A'); 
                character[idx].first++;      
                character[idx].second = s[i];
            }
            else if(s[i]>=48 && s[i]<=57){
                int idx = 52 + (s[i] - '0');
                character[idx].first++;
                character[idx].second = s[i];
            }
        }

        sort(character.begin(),character.end(),greater<pair<int,char>>());

        for(int i=0;i<62;i++){
            auto p = character[i];
            if(p.first > 0){
                while(p.first--){
                    str+=p.second;
                }
            }
        }

        return str;
    }
};
