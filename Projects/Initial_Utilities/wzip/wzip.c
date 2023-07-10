/*
However, the exact format of the compressed file is quite important; here, you will write out a 4-byte integer in 
binary format followed by the single character in ASCII. Thus, a compressed file will consist of some number of 
5-byte entries, each of which is comprised of a 4-byte integer (the run length) and the single character.

To write out an integer in binary format (not ASCII), you should use fwrite(). Read the man page for more details. 
For wzip, all output should be written to standard output (the stdout file stream, which, as with stdin, is already 
open when the program starts running).

https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-utilities
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARS_TO_WRITE 1
#define BUFFER_SIZE 2
#define CHAR_SIZE 1

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    FILE* fileStreamIn;
    FILE* fileStreamOut = stdout;
    char prevChar[BUFFER_SIZE];
    char currentChar[BUFFER_SIZE];
    int charCount = 1;

    /*
    If the count is "1" then that still needs to be included
    That also counts for the return char
    */

    for (int i = 1; i < argc; i++) {
        fileStreamIn = fopen(argv[i], "r");

        if (fileStreamIn != NULL) {
            if (i == 1) fread(prevChar, CHAR_SIZE, sizeof(char), fileStreamIn); // Get first char in the first file
            while (fread(currentChar, CHAR_SIZE, sizeof(char), fileStreamIn)) {
                
                //printf("prev: %s \n", prevChar);
                //printf("current: %s \n", currentChar);
                
                if (currentChar[0] != prevChar [0]) {
                    if (prevChar[0] != '\0') {
                        //fwrite(&charCount, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
                        fwrite(&charCount, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
                        fwrite(prevChar, sizeof(char), CHARS_TO_WRITE, fileStreamOut);   
                    }   
                    
                    charCount = 1;
                    prevChar[0] = currentChar[0];
                }
                else {
                    charCount++;
                }
            }
            fclose(fileStreamIn);
        }
    }
    fwrite(&charCount, sizeof(int), CHARS_TO_WRITE, fileStreamOut);
    fwrite(prevChar, sizeof(char), CHARS_TO_WRITE, fileStreamOut);
    
    return 0;
}

