#include<iostream>
// Built-in stack implementation
// from Standard Template Library(STL)
#include<stack>

using namespace std;

// This is basically a helper function to
// get the opposite bracket while checking
char getMatchingBracket(char ch) {
    if(ch == '(')
        return ')';
    else if(ch == '[')
        return ']';
    else if(ch == '{')
        return '}';

    if(ch == ')')
        return '(';
    else if(ch == ']')
        return '[';
    else if(ch == '}')
        return '{';
    else
        return '\0';
}

bool checkBalancedParenthesis(char *exp, int length) {
    // Make a stack to push brakcets in
    stack <char> s;
    char c;

    // Loop through the expression and
    // push the brackets in the stack
    // pop if brakcets are matched
    for (int i = 0; i < length; i++) {
        c = exp[i];

        // Check if the current character is an
        // opening bracket
        if(c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            // Here, we can have 2 conditions:
            // 1. The stack is empty
            // 2. The top of the stack is not
            //    a matching bracket
            // This would mean that the exp is invalid
            if(s.empty() || s.top() != getMatchingBracket(c)) {
                return false;
            } else {
                s.pop();
            }

        } else {
            printf("Invalid character\n");
        }
    }

    // Finally, to validate if the expression
    // is valid, we need to check if the stack is empty
    return s.empty();
}

int main() {
    char c[51];
    bool isBalanced = false;
    
    printf("Enter an expression: ");
    gets(c);

    isBalanced = checkBalancedParenthesis(c, strlen(c));

    if(isBalanced) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }
    

    return 0;
}