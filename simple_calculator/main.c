#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage e.g.: [num1] ['+'] [num2]\n");
    }
    if (argc != 4) {
        printf("Invalid parameters.\n");
        exit(1);
    }

    double a = atof(argv[1]);
    double b = atof(argv[3]);
 
    switch (*argv[2]) {
        case '+':
            printf("%lf + %lf = %.2lf\n", a, b, a + b);
            break;
        case '-':
            printf("%lf - %lf = %.2lf\n", a, b, a - b);
            break;
        case '/':
            printf("%lf / %lf = %.2lf\n", a, b, a / b);
            break;
        case '*':
            printf("%lf * %lf = %.2lf\n", a, b, a * b);
            break;
        default:
            printf("Uknown operator.\n");

    }
}
