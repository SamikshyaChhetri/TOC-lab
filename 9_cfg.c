#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RULES 10
#define MAX_EXPANSION 10

typedef struct {
    char non_terminal;
    char *expansion[MAX_EXPANSION];
    int num_expansions;
} Rule;

Rule rules[MAX_RULES];

void add_rule(char non_terminal, char *expansion[], int num_expansions) {
    rules[non_terminal - 'A'].non_terminal = non_terminal;
    for (int i = 0; i < num_expansions; i++) {
        rules[non_terminal - 'A'].expansion[i] = strdup(expansion[i]);
    }
    rules[non_terminal - 'A'].num_expansions = num_expansions;
}

void generate(char symbol) {
    if (symbol >= 'A' && symbol <= 'Z') {
        int rule_index = symbol - 'A';
        int expansion_index = rand() % rules[rule_index].num_expansions;
        for (int i = 0; i < strlen(rules[rule_index].expansion[expansion_index]); i++) {
            generate(rules[rule_index].expansion[expansion_index][i]);
        }
    } else {
        printf("%c", symbol);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    add_rule('S', (char *[]){"AB", "BC"}, 2);
    add_rule('A', (char *[]){"a", "b"}, 2);
    add_rule('B', (char *[]){"c"}, 1);
    add_rule('C', (char *[]){"d", "e"}, 2);

    printf("Generated string: ");
    generate('S');
    printf("\n");

    for (int i = 0; i < MAX_RULES; i++) {
        for (int j = 0; j < rules[i].num_expansions; j++) {
            free(rules[i].expansion[j]);
        }
    }

    return 0;
}