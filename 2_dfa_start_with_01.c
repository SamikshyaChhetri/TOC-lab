#include<stdio.h> /* Implement a DFA for L = { set of all strings over {0,1} such that string start with 01 */

#include<string.h>

enum states { q0, q1, qf, qd };

enum states delta(enum states, char);

int main() {
    char input[20];
    enum states curr_state = q0;
    int i = 0;
    
    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character from fgets result
    input[strcspn(input, "\n")] = '\0';
    
    char ch = input[i];
    while (ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }
    
    if (curr_state == qf)
        printf("\nThe string %s is accepted.\n", input);
    else 
        printf("\nThe string %s is not accepted.\n", input);
    
    return 0;
}

// Transition Function
enum states delta(enum states s, char ch) {
    enum states curr_state;
    switch (s) {
        case q0:
            if (ch == '0')
               curr_state = q1;
            else
               curr_state = qd;
            break;
        case q1:
            if (ch == '1')
               curr_state = qf;
            else
               curr_state = qd;
            break;
        case qf:
            if (ch == '0' || ch == '1')
               curr_state = qf;
            break;
        case qd:
            curr_state = qd;
            break;
    }
    return curr_state;
}
