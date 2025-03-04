#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STATES 20
#define MAX_SYMBOLS 20
#define MAX_STRING 100

typedef struct {
    int num_symbols, num_states, start_state, num_accept_states;
    int accept_states[MAX_STATES];
    int transition[MAX_STATES][MAX_SYMBOLS];
    char symbols[MAX_SYMBOLS];
} DFA;

int findSymbolIndex(char symbol, char *alphabet, int numAlphabet) {
    for (int i = 0; i < numAlphabet; i++) {
        if (alphabet[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int isAccepted(DFA *dfa, char *input) {
    int currentState = dfa->start_state;

    for (int i = 0; input[i] != '\0'; i++) {
        int symbolIndex = findSymbolIndex(input[i], dfa->symbols, dfa->num_symbols);
        if (symbolIndex == -1) {
            return 0;
        }
        currentState = dfa->transition[currentState][symbolIndex];
    }

    return dfa->accept_states[currentState];
}


int main() {
    DFA dfa;

    printf("Number of input symbols: ");
    scanf("%d", &dfa.num_symbols);

    printf("Input symbols: ");
    for (int i = 0; i < dfa.num_symbols; i++) {
        scanf(" %c", &dfa.symbols[i]);
    }

    printf("Enter number of states: ");
    scanf("%d", &dfa.num_states);

    printf("Initial state: ");
    scanf("%d", &dfa.start_state);

    printf("Number of accepting states: ");
    scanf("%d", &dfa.num_accept_states);

    printf("Accepting states: ");
    for (int i = 0; i < dfa.num_accept_states; i++) {
        scanf("%d", &dfa.accept_states[i]);
    }

    for (int i = 0; i < dfa.num_states; i++) {
        for (int j = 0; j < dfa.num_symbols; j++) {
            dfa.transition[i][j] = -1;
        }
    }

    printf("Transition table:\n");
    for (int i = 0; i < dfa.num_states; i++) {
        for (int j = 0; j < dfa.num_symbols; j++) {
            printf("State %d to %c -> ", i + 1, dfa.symbols[j]);
            scanf("%d", &dfa.transition[i][j]);
        }
    }

    char input[MAX_STRING];
    printf("Input string: ");
    scanf("%s", input);

    if (isAccepted(&dfa, input)) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }

    return 0;
}



