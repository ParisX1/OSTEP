# Notes on file reading

## FILE

FILE* filePtr = fopen(argv[i], "r");

* When we open a file, such as using fopen(), a pointer to a file stream is returned.  We can call this a "File Pointer"
* This is part of the stdio library
* "This pointer is to a file object.  The object is normally a structure that contains all the information required by the standard I/O library to manage the stream."
* To manage the stream, stdio needs:
1. The file descriptor used for io
2. A pointer to a buffer for the stream
3. The size of the buffer
4. A count of the number of characters current in the buffer
* We don't need to know the workings and implementation of FILE. To reference the file stream we just pass the FILE pointer an as argument to each stdio function.

## fopen()

* Used to open a file for reading and/or writing
* Returns a FILE* 
* When finished, used fclose() to close the file

## fwrite()

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

* fwrite() writes _nmemb_ items of data, each _size_ bytes long, to the stream pointed to by _stream_, obtaining them from
       the location given by _ptr_.

## fgets()

char *fgets(char *s, int size, FILE *stream);  

* Reads in _size_ characters from _stream_ and stores them into the buffer pointed to by _s_.  Reading stops after an EOF or a newline. 
* If a newline is read, it is stored into the buffer.  A terminating null byte ('\0') is stored after the last character in the buffer.

while (fgets(buffer, BUFFER_SIZE, filePtr)) {
	printf("%s", buffer);
}

## getline()

ssize_t getline(char **lineptr, size_t *n, FILE *stream);  

* Read an entire line from stream, storing the address of the buffer containing the text into _*lineptr_.  The buffer is
       null-terminated and includes the newline character, if one was found.
* If _*lineptr_ is set to NULL and _*n_ is set 0 before the call, then _getline()_ will allocate a buffer for storing the line.
* Returns the number of characters read, including the delimiter character, but not including the terminating null byte ('\0').

FILE* fileStream;  
char* line = NULL;  
char* searchText = argv[1];  
size_t lineLen = 0;  

fileStream = fopen(argv[i], "r");  

while (getline(&line, &lineLen, fileStream) != -1) {  
	if (isTextFound(line, searchText)) {  
            printf("%s", line);  
        }  
}  

## Mapping a File Stream to stdio -> stdin and stdout

* The important this to understand here is that stdin and stdout are file streams. stdio provides three open filestreams for us to use:

FILE *stdin;  
FILE *stdout;  
FILE *stderr;  

* Look at the manpage for stdio for more details
* The  standard I/O library provides a simple and efficient buffered stream I/O interface.  Input and output is mapped into logical data streams and the physical I/O characteristics are concealed.
* At program startup, three text streams are predefined and need not be opened explicitly: standard input  (for  reading  conventional  input),  standard  output (for writing conventional output), and standard error (for writing diagnostic output) These streams are abbreviated stdin, stdout, and stderr.
* So, we can "remap" a FILE* (file stream) to read from standard input (stdin):

// Read from stdin (user keyboard input) until EOF is triggered, printing out the same input

FILE* fileStream = stdin;
char* line = NULL;
size_t lineLen = 0;

while (getline(&line, &lineLen, fileStream) != -1) {
	printf("%s", line);
}

char* line = NULL;
    char* searchText = argv[1];
    size_t lineLen = 0;
