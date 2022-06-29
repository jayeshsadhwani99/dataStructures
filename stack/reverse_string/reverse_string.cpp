// Even though good, this is not an
// optimal solution.

// For the fastest implementation,
// we can use 2 variables,
// 1. start of the string
// 2. end of the string

// Doing this, the time complexity will
// be O(n) - the same, but
// the space complexity will be O(1)

#include<iostream>
// Built-in stack implementation
// from Standard Template Library(STL)
#include<stack>

using namespace std;

void reverse(char *c, int length) {
    stack<char> s;

    // Loop to push in the stack

    // Since the stack operations are
    // constant time, the loop will
    // have a complexity of O(n)
    for (int i = 0; i < length; i++) {
        s.push(c[i]);
    }

    // Loop to pop from the stack

    // Similarly, this loop will also
    // have a complexity of O(n)
    for(int i = 0; i < length; i++) {
        // Overwrite the original string
        c[i] = s.top();
        s.pop();
    }

    // Hence, the total complexity of
    // the function will also be O(n)

    // The space complexity, that is the extra 
    // space taken in the stack will also be
    // O(n)
}

int main() {
    char c[51];

    printf("Enter a string: ");
    gets(c);

    reverse(c, strlen(c));

    printf("Reversed string: %s\n", c);

    return 0;
}