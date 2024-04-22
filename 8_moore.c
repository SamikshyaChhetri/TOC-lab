#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STATES 3
#define NUM_INPUTS 2

// Define the Moore machine transition table
const int transition_table[NUM_STATES][NUM_INPUTS] = {
    {1, 0},  // State 0 transitions: input 0 -> state 1, input 1 -> state 0
    {2, 1},  // State 1 transitions: input 0 -> state 2, input 1 -> state 1
    {0, 0}   // State 2 transitions: input 0 -> state 0, input 1 -> state 0
};

// Define the Moore machine output table
const char* output_table[NUM_STATES] = {
    "A",  // Output for state 0
    "B",  // Output for state 1
    "C"   // Output for state 2
};

// Function to simulate the Moore machine
void run_moore_machine(const char* input_string) {
    int current_state = 0;
    printf("State: %d, Output: %s\n", current_state, output_table[current_state]);
    for (int i = 0; i < strlen(input_string); i++) {
        int input = input_string[i] - '0';
        current_state = transition_table[current_state][input];
        printf("State: %d, Output: %s\n", current_state, output_table[current_state]);
    }
}

int main() {
    char input_string[100]; // Input string buffer
    printf("Enter input string (0s and 1s only): ");
    scanf("%s", input_string);
    printf("Input: %s\n", input_string);
    run_moore_machine(input_string);
    return 0;
}