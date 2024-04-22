//The DFA that accepts all the string that contains substring 001.
#include<stdio.h>
#include<string.h>

enum states { q0, q1, q2, qf };

enum states delta(enum states, char);

int main() {
    enum states curr_state = q0;
    char string[20], ch;
    int i=0;
    
    printf("\nEnter a string: ");
    fgets(string, sizeof(string), stdin);
    
    while(string[i] != '\0' && string[i] != '\n') {
        curr_state = delta(curr_state, string[i]);
        i++;
    }
    
    if(curr_state == qf)
        printf("\nThe string '%s' is valid.\n", string);
    else 
        printf("\nThe string '%s' is not valid.\n", string);
    
    return 0;
}

enum states delta(enum states s, char ch) {
    enum states curr_state;
    
    switch(s) {
        case q0:
            if(ch == '0')
                curr_state = q1;
            else
                curr_state = q0;
            break;
        case q1:
            if(ch == '0')
                curr_state = q2;
            else
                curr_state = q0;
            break;
        case q2:
            if(ch == '0')
                curr_state = q2;
            else
                curr_state = qf;
            break;
        case qf:
            if(ch == '0' || ch == '1')
                curr_state = qf;
    }
    return curr_state;
}
