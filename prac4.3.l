%option noyywrap
%{
#include <stdio.h>
#include <ctype.h>

int char_count = 0;
int word_count = 0;
int line_count = 0;

%}

%%

\n      { line_count++; }          // Increment line count on newline
[ \t]+  { char_count += yyleng; }  // Count spaces and tabs as characters
[a-zA-Z0-9]+ { word_count++; char_count += yyleng; }  // Count words and characters
.       { char_count++; }          // Count all other characters as well

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    yyin = input_file;
    yylex();  // Begin lexical analysis

    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);

    fclose(input_file);
    return 0;
}

