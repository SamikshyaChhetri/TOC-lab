/*Write a program to implement PDA that accepts all strings over alphabetΣ={0,1} that have contain  number of 0's followed by equal number of 1s by final state.*/

#include<stdio.h>
#include<string.h>
#define MAX 100

enum states { q0, q1, q2, qf, qr };
void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states, char, char);

struct stack
{
    char symbols[MAX];
    int top;
};

struct stack s;

int main()
{
    char input[20];
    enum states curr_state = q0;
    s.top = -1;

    printf("\nEnter a binary string: ");
    fgets(input, sizeof(input), stdin);
    // Remove the newline character from fgets result
    input[strcspn(input, "\n")] = '\0';

    char ch = 'e';
    char st_top = 'e';
    curr_state = delta(curr_state, ch, st_top);

    int i = 0;
    ch = input[i];
    st_top = get_stack_top();
    int c = 0;

    while (c <= strlen(input))
    {
        curr_state = delta(curr_state, ch, st_top);
        ch = input[++i];
        st_top = get_stack_top();
        c++;
    }

    if (curr_state == qf)
        printf("\nThe string %s is accepted.\n", input);
    else
        printf("\nThe string %s is not accepted.\n", input);

    return 0;
}

enum states delta(enum states s, char ch, char st_top)
{
    enum states curr_state = qr;
    switch (s)
    {
    case q0:
        if (ch == 'e' && st_top == 'e')
        {
            curr_state = q1;
            push('$');
        }
        break;
    case q1:
        if (ch == '0' && (st_top == '$' || st_top == '0'))
        {
            curr_state = q1;
            push(ch);
        }
        else if (ch == '1' && st_top == '0')
        {
            curr_state = q2;
            pop();
        }
        else
            curr_state = qr; // qr for undefined transition
        break;
    case q2:
        if (ch == '1' && st_top == '0')
        {
            curr_state = q2;
            pop();
        }
        else if (ch == '\0' && st_top == '$')
        {
            curr_state = qf;
            pop();
        }
        else
            curr_state = qr;
        break;
    case qf: // Handle qf state
        // No specific action needed
        break;
    case qr: // Handle qr state
        // No specific action needed
        break;
    }
    return curr_state;
}

char get_stack_top()
{
    return (s.symbols[s.top]);
}

void push(char ch)
{
    if (s.top < MAX - 1)
    {
        s.symbols[++s.top] = ch;
    }
    else
    {
        printf("\nStack Full.\n");
    }
}

void pop()
{
    if (s.top > -1)
    {
        s.symbols[s.top] = ' ';
        s.top--;
    }
    else
        printf("\nStack Empty.\n");
}
