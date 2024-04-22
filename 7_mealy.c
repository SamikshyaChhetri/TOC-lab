#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STATES 3
#define NUM_INPUTS 2

// Define the Mealy machine transition table
const int transition_table[NUM_STATES][NUM_INPUTS] = {
    {1, 0},  // State 0 transitions: input 0 -> state 1, input 1 -> state 0
    {2, 1},  // State 1 transitions: input 0 -> state 2, input 1 -> state 1
    {0, 0}   // State 2 transitions: input 0 -> state 0, input 1 -> state 0
};

// Define the Mealy machine output table
const char* output_table[NUM_STATES][NUM_INPUTS] = {
    {"A", "B"},  // State 0 outputs: input 0 -> "A", input 1 -> "B"
    {"C", "D"},  // State 1 outputs: input 0 -> "C", input 1 -> "D"
    {"E", "F"}   // State 2 outputs: input 0 -> "E", input 1 -> "F"
};

// Function to simulate the Mealy machine
void run_mealy_machine(const char* input_string) {
    int current_state = 0;
    printf("State: %d, Output: %c\n", current_state, output_table[current_state][input_string[0] - '0'][0]);
    for (int i = 0; i < strlen(input_string); i++) {
        int input = input_string[i] - '0';
        current_state = transition_table[current_state][input];
        printf("State: %d, Output: %c\n", current_state, output_table[current_state][input][0]);
    }
}

int main() {
    char input_string[100]; // Input string buffer
    printf("Enter input string (0s and 1s only): ");
    scanf("%s", input_string);
    printf("Input: %s\n", input_string);
    run_mealy_machine(input_string);
    return 0;
}