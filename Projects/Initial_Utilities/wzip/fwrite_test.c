#include <stdio.h>
#include <stdlib.h>

#define CHARS_TO_WRITE 1


int main(int argc, char* argv[]) {

    if (argc <= 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE* fileStreamIn;
    FILE* fileStreamOut = stdout;
    //char* currentChar;
    //char* nextChar;
    int prevChar;
    int currentChar;
    int charCount = 91;

    fwrite(&charCount, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
    printf("\n");
    return 0;
}

