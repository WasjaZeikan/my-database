#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

int get_line(char** line) {
    int ch;
    int length = 0;
    int capacity = 50;
    char* temp = malloc(capacity * sizeof(char));
    
    if (temp == NULL) {
        add_new_error(OUT_OF_MEMORY_ERROR, "Memory allocation is not success", __FILE__, __LINE__);
        return -1;
    }

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length >= capacity - 1) {
            capacity *= 2;
            char* new_temp = realloc(temp, capacity * sizeof(char));
            if (new_temp == NULL) {
                free(temp);
                add_new_error(OUT_OF_MEMORY_ERROR, "Memory allocation is not success", __FILE__, __LINE__);
                return -1;
            }
            temp = new_temp;
        }
        temp[length++] = ch;
    }

    if (ch == EOF && length == 0) {
        free(temp);
        return -1;
    }

    temp[length] = '\0';
    temp = realloc(temp, (length + 1) * sizeof(char));
    if (temp == NULL) {
        add_new_error(OUT_OF_MEMORY_ERROR, "Memory allocation is not success", __FILE__, __LINE__);
        return -1;
    }
    *line = temp;
    return length;
}