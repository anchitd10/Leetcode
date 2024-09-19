// Problem-241: Different Ways to Find Parenthesis

// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
// Example:
// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
    vector<int> result;
    
    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        
        // If it's an operator, split the expression into two parts
        if (c == '+' || c == '-' || c == '*') {
            //left and right parts using recursion
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));

            // Combine results based on the operator
            for (int l : left) {
                for (int r : right) {
                    if (c == '+') {
                        result.push_back(l + r);
                    } else if (c == '-') {
                        result.push_back(l - r);
                    } else if (c == '*') {
                        result.push_back(l * r);
                    }
                }
            }
        }
    }

    //if no operator was found, convert the expression to integer and return it
    if (result.empty()) {
        result.push_back(stoi(expression));
    }
    
    return result;
}
};