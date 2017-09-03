#ifndef _OE_GALLOC_H
#define _OE_GALLOC_H

#include "../oecommon/defs.h"
#include "../oecommon/types.h"

OE_EXTERNC_BEGIN

void* __OE_GMalloc(
    oe_size_t size);

void __OE_GFree(
    void* ptr);

int __OE_GCheck(
    void* ptr);

oe_size_t __OE_GCount(void);

oe_bool __OE_GOwns(const void* ptr);

void __OE_GFix(void* ptr);

OE_EXTERNC_END

#endif /* _OE_GALLOC_H */
