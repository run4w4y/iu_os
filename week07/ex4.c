#include <stdlib.h>

void* realloc(void* ptr, size_t size_before, size_t size_after) {
    if (ptr == NULL)
        return malloc(size_after);
    
    if (size_after == 0) {
        free(ptr);
        return NULL;
    }
    
    char* before = (char*) ptr;
    char* after = (char*) malloc(size_after);

    for (int i = 0; i < size_before && i < size_after; ++i)
        after[i] = before[i];

    free(ptr);
    return (*void) after; 
}