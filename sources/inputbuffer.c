#include "inputbuffer.h"
#include <stdlib.h>

InputBuffer* create_new_buffer() {
    InputBuffer* buffer = malloc(sizeof(InputBuffer));
    buffer->buffer = NULL;
    buffer->buffer_size = 0;
    buffer->buffer_capacity = 0;
    return buffer;
}

void clear_buffer(InputBuffer* buffer) {
    free(buffer->buffer);
    free(buffer);
}

void read_buffer(InputBuffer* buffer) {
    buffer->buffer_size = get_line(&buffer->buffer);
    buffer->buffer_capacity = buffer->buffer_size;
}