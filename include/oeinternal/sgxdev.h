#ifndef _OE_SGXDEV_H
#define _OE_SGXDEV_H

#include "../oecommon/defs.h"
#include "../oecommon/result.h"
#include "../oecommon/types.h"
#include "../oecommon/sha.h"

OE_EXTERNC_BEGIN

#define SGX_DRIVER_MAGIC 0x50e9343f
#define SGX_MEASURER_MAGIC 0x4c6b6236

typedef struct _OE_SGXDevice OE_SGXDevice;

typedef OE_Result (*OE_ECreateProc)(
    OE_SGXDevice* dev,
    oe_uint64_t enclaveSize,
    oe_uint64_t* enclaveAddr);

typedef OE_Result (*OE_EAddProc)(
    OE_SGXDevice* dev,
    oe_uint64_t base,
    oe_uint64_t addr,
    oe_uint64_t src,
    oe_uint64_t flags,
    oe_bool extend);

typedef OE_Result (*OE_EInitProc)(
    OE_SGXDevice* dev,
    oe_uint64_t addr,
    oe_uint64_t sigstruct,
    oe_uint64_t einittoken);

typedef OE_Result (*OE_GetHash)(
    OE_SGXDevice* dev,
    OE_SHA256* hash);

typedef OE_Result (*OE_CloseProc)(
    OE_SGXDevice* dev);

typedef oe_uint32_t (*OE_GetMagic)(
    const OE_SGXDevice* dev);

struct _OE_SGXDevice
{
    OE_ECreateProc ecreate;
    OE_EAddProc eadd;
    OE_EInitProc einit;
    OE_GetHash gethash;
    OE_CloseProc close;
    OE_GetMagic getmagic;
};

OE_EXTERNC_END

#endif /* _OE_SGXDEV_H */
