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
    int currentChar;
    //int charCount;

    for (int i = 1; i < argc; i++) {
        fileStreamIn = fopen(argv[i], "r");
        if (fileStreamIn != NULL) {
            while ((currentChar = fgetc(fileStreamIn)) != EOF) {
                //currentChar = fgetc(fileStreamIn);
                fwrite(&currentChar, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
            }
            fclose(fileStreamIn);
        }
    }
    return 0;
}

