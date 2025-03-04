%option noyywrap
%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int length = 0;
int has_lower = 0;
int has_upper = 0;
int has_digit = 0;
int has_symbol = 0;

%}

%%

[a-z]          { has_lower = 1; length++; }
[A-Z]          { has_upper = 1; length++; }
[0-9]          { has_digit = 1; length++; }
[\*\;\#\$\@]    { has_symbol = 1; length++; }

.              { length++; }   // Count any other character to determine length

%%

int main() {
    char password[256];
    printf("Enter password: ");
    fgets(password, 256, stdin);

    // Remove newline character if present
    password[strcspn(password, "\n")] = 0;

    // Set the input to Lex
    YY_BUFFER_STATE buffer = yy_scan_string(password);
    yylex();
    yy_delete_buffer(buffer);

    // Validation
    if (length >= 9 && length <= 15 && has_lower && has_upper && has_digit && has_symbol) {
        printf("Valid password\n");
    } else {
        printf("Invalid password\n");
    }

    return 0;
}
