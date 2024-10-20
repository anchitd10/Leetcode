// Problem-1106: Parsing a Boolean Expression

// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
// 't' that evaluates to true.
// 'f' that evaluates to false.
// '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
// '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// Given a string expression that represents a boolean expression, return the evaluation of that expression.
// It is guaranteed that the given expression is valid and follows the given rules.
// Example 1:
// Input: expression = "&(|(f))"
// Output: false
// Explanation: 
// First, evaluate |(f) --> f. The expression is now "&(f)".
// Then, evaluate &(f) --> f. The expression is now "f".
// Finally, return false.

class Solution {
public:
    char solveOperator(vector<char>& values, char op) {
        if (op == '!') {
            return values[0] == 't' ? 'f' : 't';
        }

        if (op == '&') {
            return all_of(begin(values), end(values), [](char ch) {
                return ch == 't';
            }) ? 't' : 'f';
        }
        if (op == '|') {
            return any_of(begin(values), end(values), [](char ch) {
                return ch == 't';
            }) ? 't' : 'f';
        }
        return 't';
    }

    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (expression[i] == ',') {
                continue;
            }

            if (expression[i] == ')') {
                vector<char> values;

                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop();
                char op = st.top();
                st.pop();
                st.push(solveOperator(values, op));
            } else {
                st.push(expression[i]);
            }
        }
        return st.top() == 't';
    }
};
