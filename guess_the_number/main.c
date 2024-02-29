#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    printf("Welcome to guess the number!\n\nStart guessing by typing numbers.\n");
    int number = rand() % 101;

    for (int i = 0; i < 5; i++) {
        uint guess;
        scanf("%u", &guess);

        if (guess == number) {
            printf("Winner, winner, chicken dinner.\n");
            exit(0);
        } else if (guess < number) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
    }
    printf("Too bad, you lost.\n");
}
