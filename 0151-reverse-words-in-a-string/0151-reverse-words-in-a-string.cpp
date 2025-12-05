class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string word;
        vector<string> arr;

        // This syntax will :-  Reads tokens separated by whitespace by default. Delimiters are: spaces, tabs, newlines. Consecutive multiple spaces are treated as one separator
        while(ss>>word){ 
            cout<<"["<<word<<"]"<<endl;
            arr.push_back(word);
        }

        string str = "";
        for(int i=arr.size()-1 ;i>=0 ;i--){
            string temp = arr[i] + " ";
            str += temp;
        }

        str.pop_back();

        return str;
    }
};