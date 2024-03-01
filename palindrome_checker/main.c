#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage:\nRun the app with 1 parameter to check if it's a palindrome\n");
        exit(0);
    }
    if (argc >= 3) {
        printf("Too many args!\n");
        exit(0);
    }

    char *word = argv[1];
    size_t length = strlen(word);
    
    for (int i = 0; i < length; i++) {
        if (word[i] != word[length - (i + 1)]) {
            printf("Not a palindrome!\n");
            exit(0);
        }
    }
    printf("Palindrome!\n");
}
