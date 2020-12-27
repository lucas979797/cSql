#include <stdio.h>

typedef struct {
    size_t bufferSize;
    char* line;
    ssize_t lineLen;
} readBuffer;

void* fatalError(char* fmt, ...);
void printWelcome();
readBuffer* createReadBuffer();
void readReplLine(readBuffer* rb);
void closeReadBuffer(readBuffer* rb);