#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>

#define STRING_LENGTH 100

enum ERROR_TYPE {
    OUT_OF_MEMORY_ERROR
};

typedef struct Error {
    enum ERROR_TYPE type;
    char message[STRING_LENGTH];
    char file[STRING_LENGTH];
    int line;
} Error;

void add_new_error(enum ERROR_TYPE type, const char* message, const char* file, int line);
void print_all_errors();
void clear_errors();
void print_error(int error_index);

#endif