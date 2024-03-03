#include<stdlib.h>
#include<stdio.h>

void encrypt_ceasar(int shift) {
    if (shift < 0) {
        shift = 26 - (shift * -1);
        if (shift < 0) {
            shift *= -1;
        }
    }
    shift = shift % 26;

    FILE *original;    
    FILE *encrypted;    

    original = fopen("original.txt", "r");
    encrypted = fopen("encrypted.txt", "w");
    
    char c = 0;
    while ((c = fgetc(original)) != EOF) {
        unsigned char new_c = 0;
        if (c >= 65 && c <= 90)  {
            new_c = c + shift;
            if (new_c > 90) {
                new_c -= 26;
            }
            fputc(new_c, encrypted);
        } else if (c >= 97 && c <= 122) {
            new_c = c + shift;
            if (new_c > 122) {
                new_c = (c + shift) - 26;
            }
            fputc(new_c, encrypted);
        } else {
            fputc(c, encrypted);
        }
    }

    fclose(original);
    fclose(encrypted);
}

void decrypt_ceasar(int shift) {
    if (shift < 0) {
        shift = 26 - (shift * -1);
        if (shift < 0) {
            shift *= -1;
        }
    }
    shift = shift % 26;

    FILE *encrypted;    
    FILE *decrypted;    

    decrypted = fopen("decrypted.txt", "w");
    encrypted = fopen("encrypted.txt", "r");
    
    char c = 0;
    while ((c = fgetc(encrypted)) != EOF) {
        unsigned char new_c = 0;
        if (c >= 65 && c <= 90)  {
            new_c = c - shift;
            if (new_c < 65) {
                new_c += 26;
            }
            fputc(new_c, decrypted);
        } else if (c >= 97 && c <= 122) {
            new_c = c - shift;
            if (new_c < 97) {
                new_c += 26;
            }
            fputc(new_c, decrypted);
        } else {
            fputc(c, decrypted);
        }
    }

    fclose(decrypted);
    fclose(encrypted);
}

int main(void) {
    FILE *original;    
    original = fopen("original.txt", "w");
    fprintf(original, "Hey! My name is Sven. Hope you have a nice day.\n");    
    fprintf(original, "Let me add this second line for funz.\n");    
    fclose(original);

    encrypt_ceasar(-1568);
    decrypt_ceasar(-1568);
}
