//
// Created by lucasg on 27/05/18.
//

#ifndef MINILIBC_MEMORY_H
#define MINILIBC_MEMORY_H

/* ALLOCATION */
#define MEM_ALLOC(type, size) malloc(sizeof(type) * size)
#define MEM_PROTECT_ALLOC(ptr, critical) if (!(ptr)) {RETURN(critical);};

#define MEM_FREE(ptr) free(ptr)

/* POINTERS OP */

#define POINT_OFFSET_PTR(ptr, offset, ptrval) *(ptr + offset) = *ptrval;
#define POINT_OFFSET_VAL(ptr, offset, value) *(ptr + offset) = value;

#endif //MINILIBC_MEMORY_H
