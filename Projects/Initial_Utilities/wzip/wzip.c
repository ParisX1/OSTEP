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
    int charCount = 1;

    for (int i = 1; i < argc; i++) {

        fileStreamIn = fopen(argv[i], "r");

        if (fileStreamIn != NULL) {

            prevChar = fgetc(fileStreamIn); // Get first char in file

            while ((currentChar = fgetc(fileStreamIn)) != EOF) {

                if (currentChar != prevChar) {
                    if (charCount > 1) {
                        fwrite(&charCount, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
                        charCount = 0;
                    }
                    fwrite(&prevChar, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
                    prevChar = currentChar;
                }
                else {
                    charCount++;
                }

            }
            if (charCount > 1) fwrite(&charCount, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
            fwrite(&prevChar, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
            fclose(fileStreamIn);
        }
    }
    
    return 0;
}

