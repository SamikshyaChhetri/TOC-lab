#include <stdio.h>

// Define states of the NFA
enum states { q0, q1, q2, qf };

// Function prototypes
enum states delta(enum states, char);

int main() {
    char input[20];
    enum states curr_state = q0;
    int i = 0;

    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin); // Read input

    char ch = input[i];
    while (ch != '\0' && ch != '\n') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    if (curr_state == qf)
        printf("\nThe string %s is accepted.", input);
    else
        printf("\nThe string %s is not accepted.", input);

    return 0;
}

// Define transition function delta
enum states delta(enum states s, char ch) {
    enum states next_states[4][2] = {
        {q1, q0},   // Transition from q0
        {q2, q0},   // Transition from q1
        {q2, qf},   // Transition from q2
        {q2, q0}    // Transition from qf
    };

    switch (s) {
        case q0:
            return ch == '0' ? next_states[q0][0] : next_states[q0][1];
        case q1:
            return ch == '1' ? next_states[q1][0] : next_states[q1][1];
        case q2:
            return ch == '1' ? next_states[q2][0] : next_states[q2][1];
        case qf:
            return next_states[qf][0]; // No transitions from qf
    }

    return s;
}