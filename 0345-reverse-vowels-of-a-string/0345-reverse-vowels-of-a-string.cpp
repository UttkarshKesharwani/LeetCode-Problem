class Solution {
public:      
    
    bool checkIfVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            return true;
        }
        return false;
    }

    string reverseVowels(string s) {

        int n=s.size();
        deque<int> dq; // deque is used because we need to process the element from starting as well as from the end simultaneously

        for(int i=0;i<n;i++){
            if(checkIfVowel(s[i])){
                dq.push_back(i);
            }
        }

        int size = dq.size();
           while(dq.size() > 1){
            int idx1 = dq.front();
            int idx2 = dq.back();
            dq.pop_front();
            dq.pop_back();
            swap(s[idx1], s[idx2]);
        }
        

        return s;
    }
};