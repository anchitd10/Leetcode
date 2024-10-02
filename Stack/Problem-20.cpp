// Problem-20: Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Example 2:
// Input: s = "()[]{}"
// Output: true

//STL
class Solution {
public:
    bool isValid(string s) {
         stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if (st.empty() || 
                    (c == ')' && st.top() != '(') || 
                    (c == '}' && st.top() != '{') || 
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

//Stack using Linked List
struct StackNode {
    char data;
    StackNode* next;
    StackNode(char x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;
public:
    Stack() { top = nullptr; }

    void push(char x) {
        StackNode* node = new StackNode(x);
        node->next = top;
        top = node;
    }

    char pop() {
        if (top == nullptr) return '#';
        char temp = top->data;
        StackNode* tempNode = top;
        top = top->next;
        delete tempNode;
        return temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    char peek() {
        if (top == nullptr) return '#';
        return top->data;
    }
};

class Solution {
public:
    bool isValid(string s) {
        Stack stack;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                char topElement = stack.pop();
                if ((c == ')' && topElement != '(') ||
                    (c == '}' && topElement != '{') ||
                    (c == ']' && topElement != '[')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
};