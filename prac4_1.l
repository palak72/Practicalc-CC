%option noyywrap
%{
   #include <stdio.h>
%}

%%

[0-9]+    { printf("%s\n", yytext); }  // Print each number found
[ \t\n]+  ;  // Ignore spaces, tabs, and newlines
.         ;  // Ignore all other characters

%%

int main()
{
    char input[1000];  // Buffer to store input

    printf("Enter the input string:\n");
    fgets(input, sizeof(input), stdin);  // Read input string

    YY_BUFFER_STATE buffer = yy_scan_string(input);  // Process input as a string
    yylex();  // Call lexical analyzer
    yy_delete_buffer(buffer);  // Free buffer memory

    return 0;
}
