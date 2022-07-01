// For simplicity, we assume that 
// each operand takes a single space.
// And that the input is a valid 
// postfix expression.

#include<iostream>
// Built-in stack implementation
// from Standard Template Library(STL)
#include<stack>
// To check if it's a digit
#include <ctype.h>

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

int evaluatePostfix(char *exp, int length) {
    // Stack to put the values in
    stack <char> s;
    char c;
    int op1, op2, result;

    for(int i = 0; i < length; i++) {
        c = exp[i];

        // If the current character is a 
        // digit (operand), then push it
        // on to a stack
        if(isdigit(c)) {
            s.push(c);
        } else if (isOperator(c)) {
            // If the current character is an
            // operator, then pop the top two
            // elements from the stack - To
            // get the operands for the calculation

            // C and C++ automatically convert
            // char to int
            // We are substracting 0,
            // to remove the ASCII values
            op1 = s.top() - ((int)s.top() >= 48 ? '0' : 0);
            s.pop();
            op2 = s.top() - ((int)s.top() >= 48 ? '0' : 0);
            s.pop();

            // Perform the calculation
            // and push the result back to the stack
            result = performCalculation(op2, op1, c);
            s.push(result);
        } else {
            printf("Invalid character\n");
            return 0;
        }
    }

    // After the loop, the stack should have
    // only one element left, which is the result
    return s.top();
}

int main() {
    char c[51];
    int value;

    printf("Enter an expression: ");
    gets(c);

    value = evaluatePostfix(c, strlen(c));

    printf("Value of the expression: %d\n", value);

    return 0;
}