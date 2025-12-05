class Solution {
public:

    unordered_set<int> visited; // help to store the idx of the vowel present at the end 
      
    bool checkIfVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }

    int findVowelFromLast(string s,int n){
        for(int i=n-1;i>=0;i--){
            if(not visited.count(i) && checkIfVowel(s[i])){
                visited.insert(i);
                return i;
            }
        }
        return -1;
    }

    string reverseVowels(string s) {

        int n=s.size();

        for(int i=0;i<n;i++){
            if(checkIfVowel(s[i])){
                int idx = findVowelFromLast(s,n);
                if(idx == -1) return s;
                if(idx == i) continue; 
                if(i > idx) break;
                swap(s[i],s[idx]);
            }
        }

        return s;
    }
};