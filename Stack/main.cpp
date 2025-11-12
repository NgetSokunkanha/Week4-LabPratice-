#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

bool isOpen(char c) {
    return c == '(' || c == '{' || c == '[';
}

bool isClose(char c) {
    return c == ')' || c == '}' || c == ']';
}

bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

void checkBrackets(string s) {
    Stack<char> st(s.length());  


    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!isOpen(c) && !isClose(c)) {
            continue;
        }

        if (isOpen(c)) {
            st.push(c);
        } else {
            if (st.empty()) {
                cout << "ERROR at position " << i + 1 << ": extra closing bracket" << endl;
                return;
            }
            char top = st.pop();
            if (!match(top, c)) {
                cout << "ERROR at position " << i + 1 << ": mismatch" << endl;
                return;
            }
        }
    }

    if (!st.empty()) {
        cout << "ERROR: missing closing bracket(s)" << endl;
    } else {
        cout << "All brackets are balanced!" << endl;
    }
}

int main() {
    string s = "())){]}";
    cout << "Checking: " << s << endl;
    cout << endl;
    
    checkBrackets(s);

    return 0;
}
