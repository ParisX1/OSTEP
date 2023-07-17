#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE 4
#define CHAR_SIZE 1
#define ITEMS_TO_READ 1

int main(int argc, char* argv[]) {

    if (argc <= 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE* fileStreamIn;
    char currentChar = '\0';
    int currentInt = 0;

    for (int i = 1; i < argc; i++) {
        fileStreamIn = fopen(argv[i], "r");
        if (fileStreamIn != NULL) {
            while (fread(&currentInt, INT_SIZE, ITEMS_TO_READ, fileStreamIn)) {
                fread(&currentChar, CHAR_SIZE, ITEMS_TO_READ, fileStreamIn);
                for (int chars = 0; chars < currentInt; chars++) {
                    printf("%c", currentChar);
                }
            }
        }
        fclose(fileStreamIn);
    }
    return 0;
}