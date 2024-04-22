//Write a program to find prefixes, suffixes and substring from given string.

#include<stdio.h>
#include<string.h>

void find_prefix(char string[]);
void find_suffix(char string[]);
void find_substring(char string[], int i, int j);

int main() {
    char string[20];
    int i, j;
    
    printf("\nEnter a string: ");
    fgets(string, sizeof(string), stdin);
    // Remove the newline character from fgets result
    string[strcspn(string, "\n")] = '\0';
    
    printf("\nPrefixes:");
    find_prefix(string);
    
    printf("\nSuffixes:");
    find_suffix(string);
    
    printf("\nEnter i and j for substring: ");
    scanf("%d%d", &i, &j);
    find_substring(string, i, j);
    
    return 0;
}

void find_prefix(char string[]) {
    int i, j;
    char prefix[20];
    for(i = 0; i < strlen(string); i++) {
        for(j = 0; j <= i; j++) {
            prefix[j] = string[j];
        }
        prefix[j] = '\0';
        printf("\n%s", prefix);
    }
}

void find_suffix(char string[]) {
    int i, j, k;
    char suffix[20];
    for(i = 0; i <= strlen(string); i++) {
        k = i;
        for(j = 0; j < strlen(string); j++) {
            suffix[j] = string[k];
            k++;
        }
        suffix[j] = '\0';
        printf("\n%s", suffix);
    }
}

void find_substring(char string[], int x, int y) {
    if (x < 1 || y < x || y > strlen(string)) {
        printf("Invalid input for substring\n");
        return;
    }
    
    char substr[20];
    int k = 0;
    for(int i = x - 1; i < y; i++) {
        substr[k] = string[i];
        k++;
    }
    substr[k] = '\0';
    printf("\nSubstring:\n%s", substr);
}
