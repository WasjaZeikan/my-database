#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include "util.h"

typedef struct InputBuffer {
    char* buffer;
    int buffer_size;
    int buffer_capacity;
} InputBuffer;

InputBuffer* create_new_buffer();
void clear_buffer(InputBuffer* buffer);
void read_buffer(InputBuffer* buffer);
#endif