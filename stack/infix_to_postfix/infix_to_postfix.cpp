// For simplicity, we assume that 
// each operand takes a single space.
// And that the input is a valid 
// infix expression.

#include<iostream>
// Built-in stack implementation
// from Standard Template Library(STL)
#include<stack>
// To check if it's a digit
#include <ctype.h>
// To work with strings
#include<string>

using namespace std;

// Check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int performCalculation(int a, int b, char ch) {
    switch(ch) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool hasHigherPrecendence(char top, char val) {
    switch(val) {
        case '+':
            return (top == '*' || top == '/');
        case '-':
            return (top == '*' || top == '/' || top == '+');
        case '*':
            return (top == '/');
        default:
            return false;
    }
}

string infixToPostfix(char *exp, int length) {
    // Stack to put the values in
    stack <char> s;
    char c;
    string result;

    for(int i = 0; i < length; i++) {
        c = exp[i];

        // If the current character is an
        // operand, we can just add it to the
        // result expression
        if(isdigit(c) || isalpha(c)) {
            result += c;
        } else if(isOperator(c)) {
            // Check the stack for any higher
            // precedence operator
            while(!s.empty() && hasHigherPrecendence(s.top(), c)) {
                result += s.top();
                s.pop();
            }

            // Push the current operator in the stack
            s.push(c);
        } else {
            printf("Invalid character\n");
            return NULL;
        }
    }

    // When the loop is done, we might
    // still have a few operators in
    // the stack. Now we just append 
    // them to the result expression.
    while(!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    char c[51];
    string exp;

    printf("Enter an expression: ");
    gets(c);

    exp = infixToPostfix(c, strlen(c));

    printf("Postfix expression is:\n");

    // cout works better with strings
    cout << exp << "\n";

    return 0;
}