//
// Created by deathshot on 6/23/18.
//

#include <stddef.h>
#include <stdlib.h>

void *CDA_malloc(size_t size) {
    void *mem = malloc(size);
    if (mem == NULL && size > 0)
        abort();
    return mem;
}

void CDA_free(void *mem) {
    if (mem != NULL)
        free(mem);
}

void *CDA_calloc(size_t size, size_t entry_size) {
    void *mem = calloc(size, entry_size);
    if (mem == NULL && size > 0)
        abort() ;
    return mem;
}