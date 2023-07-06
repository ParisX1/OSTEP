#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isTextFound(char* linePtr, char* searchText);

int main(int argc, char* argv[]) {

    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    FILE* fileStream;
    char* line = NULL;
    char* searchText = argv[1];
    size_t lineLen = 0;

    if (argc == 2) {
        fileStream = stdin;
    }

    if (argc >= 3) {
        for (int i = 2; i < argc; i++) {
            fileStream = fopen(argv[i], "r");
            if (fileStream == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
        }
    }

    while (getline(&line, &lineLen, fileStream) != -1) {
        if (isTextFound(line, searchText)) {
            printf("%s", line);
        }
    }

    free(line);
    fclose(fileStream);
    return 0;
}

bool isTextFound(char* linePtr, char* searchText) {
    return strstr(linePtr, searchText) != NULL;
}