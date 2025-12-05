class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        string str = "";
        int j=0;

        for(int i=0;i<min(m,n);i++){
            str.push_back(word1[i]);
            str.push_back(word2[j]);
            j++;
        }

        if(m>n){
            // word1.size() > word2.size()
            for(int i=min(m,n) ; i<m ; i++) str.push_back(word1[i]);
        }else{
            // word2.size() > word1.size()
            for(int i=min(m,n) ; i<n ; i++) str.push_back(word2[i]);
        }        

        return str;
    }
};