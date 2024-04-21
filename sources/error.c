#include "error.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Error* errors = NULL;
int error_count = 0;
int error_capacity = 0;

void add_new_error(enum ERROR_TYPE type, const char* message, const char* file, int line) {
    Error error;
    error.line = line;
    error.type = type;
    strncpy(error.file, file, STRING_LENGTH - 1);
    strncpy(error.message, message, STRING_LENGTH - 1);
    if (error_count >= error_capacity) {
        if (error_capacity == 0) {
            error_capacity = 5;
            errors = malloc(error_capacity * sizeof(Error));
        } else {
            error_capacity += 5;
            errors = realloc(errors, error_capacity * sizeof(Error));
        }
    } 
    errors[error_count++] = error;       
}

void print_all_errors() {
    for (int i = 0; i < error_count; i++) {
        print_error(i);
    }
}

void clear_errors() {
    free(errors);
    error_capacity = 0;
    error_count = 0;
}

void print_error(int error_index) {
    Error error = errors[error_index];
    printf("Error in file \"%s\":%d:\n", error.file, error.line);
    printf("Message: %s\n", error.message);
}