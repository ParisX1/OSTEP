#include<stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char* argv[]) {

    char buffer[BUFFER_SIZE];
    FILE* filePtr;
    
    for (int i = 1; i < argc; i++) {
    
        filePtr = fopen(argv[i], "r");
        if (filePtr == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        while (fgets(buffer, BUFFER_SIZE, filePtr)) {
            printf("%s", buffer);
        }
        fclose(filePtr);
    }
    
    return 0;
}