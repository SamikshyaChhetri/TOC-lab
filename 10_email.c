#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidEmail(const char *email) {
    int atCount = 0;
    int dotCount = 0;
    const char *atPos = NULL;
    const char *dotPos = NULL;

    if (!email) return 0;

    while (*email) {
        if (*email == '@') {
            if (++atCount > 1) return 0;  // More than one '@' character
            atPos = email;
        } else if (*email == '.') {
            dotCount++;
            dotPos = email;
        } else if (!isalnum(*email) && *email != '_' && *email != '-') {
            return 0;  // Invalid character
        }

        email++;
    }

    // Must contain exactly one '@', at least one dot after '@', and domain part should be at least 2 chars long
    return atCount == 1 && dotCount > 0 && dotPos && (dotPos > atPos) && strlen(dotPos) > 1;
}

int isValidPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);
    
    if (length < 8 || length > 20) return 0; // Length check

    while (*password) {
        if (isupper(*password)) hasUpper = 1;
        else if (islower(*password)) hasLower = 1;
        else if (isdigit(*password)) hasDigit = 1;
        else hasSpecial = 1; // Assume any other character is a special character

        password++;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char email[100];
    char password[100];

    printf("Enter an email: ");
    scanf("%s", email);
    printf("Enter a password: ");
    scanf("%s", password);

    if (isValidEmail(email)) {
        printf("Email is valid.\n");
    } else {
        printf("Email is invalid.\n");
    }

    if (isValidPassword(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid.\n");
    }

    return 0;
}