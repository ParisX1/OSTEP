#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT_TEXT "wish> "
#define LINE_TERMINATE '\0'
#define EXIT_TEXT "exit"
#define BUFFER_SIZE 1024
#define DELIMITER ' '

int main(int argc, char* argv[]) {
    
    //char inputBuffer[BUFFER_SIZE];

    FILE* fileStream;
    char* line = NULL;
    size_t lineLen = 0;

    if (argc == 1)  {
        fileStream = stdin;
    }
    else {
        fileStream = stdin;
    }

    while (true) {
        // Add ability to use cd
        
        printf("%s", PROMPT_TEXT);
        lineLen = getline(&line, &lineLen, fileStream); 
        line[lineLen-1] = LINE_TERMINATE;
        if (strcmp(line, EXIT_TEXT) == 0) exit(0);
    }

    return 0;

}