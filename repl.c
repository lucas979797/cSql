#include "csql.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc > 1) {
        printf("Running commands: ");
        for (int i = 1; i < argc; i++) {
            printf("[%s] ", argv[i]);
        }
        puts("");
        return 0;
    }

    printWelcome();
    readBuffer* rb = createReadBuffer();

    while (true) {
        readReplLine(rb);
        if (strcmp(rb->line, "quit") == 0 || strcmp(rb->line, "q") == 0) {
            puts("quitting cSql...");
            break;
        }
    }

    closeReadBuffer(rb);
    return 0;
}

void printWelcome() {
    printf("Welcome to cSql\n\t-Type q or quit to exit\n\n");
}

readBuffer* createReadBuffer() {
    readBuffer* rb = malloc(sizeof(readBuffer));
    *rb = (readBuffer) { .bufferSize = 0, .line = NULL, .lineLen = 0 };
    if (rb) {
        return rb;
    } else {
        return fatalError("Failed to create read buffer");
    }
}

void readReplLine(readBuffer* rb) {
    //ssize t can be negative
    printf("cSql > ");
    ssize_t lineLen = getline(&(rb->line), &(rb->bufferSize), stdin);
    if (lineLen <= 0) {
        fatalError("Failed to read line");
    } else {
        //remove newline
        rb->lineLen = lineLen - 1;
        rb->line[lineLen - 1] = '\0';
    }
}

void closeReadBuffer(readBuffer* rb) {
    free(rb->line);
    free(rb);
}
