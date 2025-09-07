class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]=='*'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }   

        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());

        return result;
    }
};