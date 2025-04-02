#include <iostream>
#include <stack>
#include <regex>
using namespace std;

bool isValidForLoopSyntax(const string& loop) {
    regex forRegex("^for\\s*\\(.*;.*;.*\\)\\s*\\{.*\\}$");
    return regex_match(loop, forRegex);
}

bool isValidWhileLoopSyntax(const string& loop) {
    regex whileRegex("^while\\s*\\(.*\\)\\s*\\{.*\\}$");
    return regex_match(loop, whileRegex);
}

bool isValidDoWhileLoopSyntax(const string& loop) {
    regex doWhileRegex("^do\\s*\\{.*\\}\\s*while\\s*\\(.*\\);$");
    return regex_match(loop, doWhileRegex);
}

bool isValidLoop(const string& loop) {
    if (loop.find("for") == 0) {
        return isValidForLoopSyntax(loop);
    }
    if (loop.find("while") == 0) {
        return isValidWhileLoopSyntax(loop);
    }
    if (loop.find("do") == 0) {
        return isValidDoWhileLoopSyntax(loop);
    }
    return false;
}

bool areBracesBalanced(const string& loop) {
    stack<char> braces;
    for (char c : loop) {
        if (c == '{') braces.push(c);
        if (c == '}') {
            if (braces.empty()) return false;
            braces.pop();
        }
    }
    return braces.empty();
}

bool areParenthesesBalanced(const string& loop) {
    stack<char> parentheses;
    for (char c : loop) {
        if (c == '(') parentheses.push(c);
        if (c == ')') {
            if (parentheses.empty()) return false;
            parentheses.pop();
        }
    }
    return parentheses.empty();
}

int main() {
    string loopCode;
    cout << "Enter the loop code to analyze: ";
    getline(cin, loopCode);

    if (!areParenthesesBalanced(loopCode) || !areBracesBalanced(loopCode)) {
        cout << "Syntax Error: Unmatched parentheses or braces!" << endl;
        return 0;
    }

    if (isValidLoop(loopCode)) {
        cout << "Valid Loop Syntax!" << endl;
    } else {
        cout << "Syntax Error: Invalid loop syntax!" << endl;
    }

    return 0;
}

