// Problem-726: Number of atoms

// Given a string formula representing a chemical formula, return the count of each atom.
// The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
// One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.
// For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.
// For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a formula.
// For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.
// The test cases are generated so that all the values in the output fit in a 32-bit integer.
// Example
// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<pair<string, int>> st;

        for(int i = 0; i < n; i++){
            char ch = formula[i];

            if(isupper(ch)){
                string element = "";
                element += ch;
                int j;
                for(j = i + 1; j < n; j++){
                    ch = formula[j];
                    if(!islower(ch)) break;
                    element += ch;
                }

                string sdigit = "";
                int k;
                for(k = j; k < n; k++){
                    ch = formula[k];
                    if(!isdigit(ch)) break;
                    sdigit += ch;
                }

                if(sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);

                st.push({element, digit});
                i = k - 1;
            }

            else if(ch == '('){
                st.push({"(", -1});
            }

            else if(ch == ')'){
                string sdigit = "";
                int j;
                for(j = i + 1; j < n; j++){
                    ch = formula[j];
                    if(!isdigit(ch)) break;
                    sdigit += ch;
                }

                if(sdigit == "") sdigit = "1";
                int digit = stoi(sdigit);
                vector<pair<string, int>> temp;
                pair<string, int> openingPair = {"(", -1};
                while(st.top() != openingPair){
                    pair<string, int> p = st.top();
                    st.pop();
                    temp.push_back({p.first, p.second * digit});
                }
                st.pop();

                while(!temp.empty()){
                    st.push(temp.back());
                    temp.pop_back();
                }
                i = j - 1;
            }
        }

        map<string, int> mp;
        while(!st.empty()){
            pair<string, int> p = st.top();
            st.pop();
            mp[p.first] += p.second;
        }

        string ans = "";
        for(auto p : mp){
            string element = p.first;
            string sdigit = to_string(p.second);
            if(sdigit == "1") sdigit = "";

            ans += element + sdigit;
        }
        return ans;
    }
};
