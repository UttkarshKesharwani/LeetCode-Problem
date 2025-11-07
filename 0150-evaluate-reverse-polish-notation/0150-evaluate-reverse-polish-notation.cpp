class Solution {
public:

    bool checkIfOperator(string str){
        if(str == "+" || str == "-" || str == "*" || str == "/") return true;
        return false;
    }

    int performOperation(int firstOperand , int secondOperand , string op){

        if(op == "+")
            return firstOperand + secondOperand;
        else if(op == "-")
            return firstOperand - secondOperand;
        else if(op == "*")
            return firstOperand * secondOperand;
        else
            return firstOperand / secondOperand;
    

        return -2;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        int n=tokens.size();

        for(int i=0;i<n;i++){

            bool isOperator = checkIfOperator(tokens[i]);

            if(isOperator){

                int secondOperand = st.top() ;
                st.pop();
                int firstOperand = st.top() ;
                st.pop();

                int result = performOperation(firstOperand,secondOperand,tokens[i]);
                st.push(result);

            }else{
                st.push(stoi(tokens[i]));
            }

        }

        return  st.top();
    }
};