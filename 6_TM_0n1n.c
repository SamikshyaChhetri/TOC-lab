//TM

#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 100

enum State { q0, q1, q2, q3, q4, qr };

int main() {
    char input[BUFFER_SIZE];
    enum State curr_state = q0;
    int i;

    printf("\nEnter a binary string: ");
    fgets(input, BUFFER_SIZE, stdin);

    // Remove the newline character from fgets result
    input[strcspn(input, "\n")] = '\0';

    int count_0 = 0;
    int count_1 = 0;

    for(i = 0; input[i] != '\0'; i++) {
        if (input[i] == '0') {
            count_0++;
        } else if (input[i] == '1') {
            count_1++;
        } else {
            printf("\nInvalid character detected: %c\n", input[i]);
            return 1; // Exit with error
        }
    }

    if (count_0 == 0 || count_1 == 0 || count_0 != count_1) {
        printf("\nThe string is not accepted.\n");
    } else {
        printf("\nThe string is accepted.\n");
    }

    return 0;
}
