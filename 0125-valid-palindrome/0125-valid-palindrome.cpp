class Solution {
public:

    bool checkPalindrom(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
      
    bool isPalindrome(string s) {

        string str = "";

        for(int i=0;i<s.size();i++){
            int ascii = (int)s[i];
            if((ascii>=97 && ascii<=122) || (ascii>=65 && ascii<=90) || (ascii>=48 && ascii<=57)){
                // convert uppercase to lowercase
                if(ascii>=65 && ascii<=90){
                    str += char(ascii + 32);   
                } else {
                    str += s[i];
                }
            }
        }
        
        return checkPalindrom(str);   
    }
};