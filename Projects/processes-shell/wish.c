#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT_TEXT "wish> "
#define EXIT_TEXT "exit"
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    
    //char inputBuffer[BUFFER_SIZE];

    FILE* fileStream;
    char* line = NULL;
    size_t lineLen = 0;

    if (argc == 1)  {
        printf("%s", PROMPT_TEXT);
        fileStream = stdin;
    }
    else {
        fileStream = stdin;
    }

    while (strcmp(getline(&line, &lineLen, fileStream), EXIT_TEXT) != 0) {
        //fgets(buffer, inputBuffer, stdin);
        printf("%s", PROMPT_TEXT);
    }

    return 0;

}