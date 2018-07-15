//
// Created by deathshot on 6/23/18.
//

#ifndef MASTER_2_7_CDA_H
#define MASTER_2_7_CDA_H

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define CDA_TRUE                (1)
#define CDA_FALSE               (0)

#define CDA_ASSERT(exp)         (assert((exp)))
#define CDA_CARD(arr)           (sizeof((arr))/sizeof(*(arr)))
#define CDA_NEW(type)           ((type *)CDA_malloc(sizeof(type)))
#define CDA_NEW_STR(str)        (strcpy((char *)malloc(strlen((str)) + 1), (str)))
#define CDA_NEW_STR_IF(str)     ((str) == NULL ? NULL : CDA_NEW_STR((str)))

typedef int             CDA_BOOL_t;
typedef signed char     CDA_INT8_t;
typedef unsigned char   CDA_UINT8_t;

// Prototypes for public functions goes down here..

void *CDA_malloc(size_t size);

void CDA_free(void *mem);

void *CDA_calloc(size_t size, size_t entry_size);

#endif //MASTER_2_7_CDA_H
