#pragma once

#define CPOLY_OFFSETOF(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->interfaces.MEMBER)
#define CPOLY_CONTAINER_OF(ptr, type, member) ({          \
        const typeof( ((type *)0)->interfaces.member ) *__mptr = (const typeof( ((type *)0)->interfaces.member ) *)(ptr); \
        (type *)( (char *)__mptr - CPOLY_OFFSETOF(type, member) ); })

#define DYNAMIC_CAST(ptr, type, member)  \
    (CPOLY_IS_CLASS(ptr, type) ? CPOLY_CONTAINER_OF(ptr, struct type, member) : NULL)
#define CPOLY_CLASS_ID(className) className##vtblObj.id
#define CPOLY_IMPLER_ID_BY_INTERFACE(interface) interface->implerID
#define CPOLY_IS_CLASS(interfacePtr, className) (CPOLY_IMPLER_ID_BY_INTERFACE(interfacePtr) == CPOLY_CLASS_ID(className))

#define CPOLY_BIND_INTERFACE(interface, className) .interface.implerID = (unsigned long long)&className##vtblObj

#define CPOLY_IMPL(interface) struct interface interface
#define CPOLY_OVERRIDE(interface, virtual_func, className, implFn) .interface.virtual_func = implFn, \
            CPOLY_BIND_INTERFACE(interface, className)

#define CPOLY_CAST_UP(interface, class) \
    &((class)->interfaces.interface)

#define CPOLY_INTERFACE \
    unsigned long long implerID;


// new macros 
#define CPOLY_CLASS(className)         \
    struct className##vtbl \
    {                            \
        unsigned long long id;

#define CPOLY_FIELD_BEGIN(className) \
    }                          \
    ;                          \
    struct className           \
    {                          \
        struct className##vtbl interfaces;

#define CPOLY_FIELD_END(className) \
    }                        \
    ;                        \
    extern struct className##vtbl className##vtblObj;

#define CPOLY_OVERRIDES_BEGIN(className)                            \
    struct className##vtbl className##vtblObj = { \
        .id = (unsigned long long)&className##vtblObj,

#define CPOLY_OVERRIDES_END(className) \
    }                            \
    ;

#define CPOLY_COPY_VTBL(className) \
    .interfaces = className##vtblObj,

#define CPOLY_DEF_OBJ(className, objName) \
    struct className objName = {    \
        CPOLY_COPY_VTBL(className)}
