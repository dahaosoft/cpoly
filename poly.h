#pragma once

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->interfaces.MEMBER)
#define container_of(ptr, type, member) ({          \
        const typeof( ((type *)0)->interfaces.member ) *__mptr = (const typeof( ((type *)0)->interfaces.member ) *)(ptr); \
        (type *)( (char *)__mptr - offsetof(type, member) ); })

#define DYNAMIC_CAST(ptr, type, member)  \
    (IS_CLASS(ptr, type) ? container_of(ptr, struct type, member) : NULL)
#define CLASS_ID(className) className##vtblObj.id
#define IMPLER_ID_BY_INTERFACE(interface) interface->implerID
#define IS_CLASS(interfacePtr, className) (IMPLER_ID_BY_INTERFACE(interfacePtr) == CLASS_ID(className))

#define POLY struct { unsigned long long id ; 
#define POLY_END  } interfaces
#define COPY_POLY(className) .interfaces = className##obj.interfaces
#define CLASS_OBJ(className) const struct className className##obj
#define CLASS_OBJ_ID(className) .interfaces.id = (unsigned long long)&className##obj
#define BIND_INTERFACE(interface, className) .interface.implerID = (unsigned long long)&className##vtblObj

#define IMPL(interface) struct interface interface
#define OVERRIDE(interface, virtual_func, className, implFn) .interface.virtual_func = implFn, \
            BIND_INTERFACE(interface, className)

#define CAST_UP(interface, class) \
    &((class)->interfaces.interface)

#define _INTERFACE_ \
    unsigned long long implerID;


// new macros 
#define CLASS(className)         \
    struct className##vtbl \
    {                            \
        unsigned long long id;

#define FILES_BEGIN(className) \
    }                          \
    ;                          \
    struct className           \
    {                          \
        struct className##vtbl interfaces;

#define FILES_END(className) \
    }                        \
    ;                        \
    extern struct className##vtbl className##vtblObj;

#define OVERRIDES_BEGIN(className)                            \
    struct className##vtbl className##vtblObj = { \
        .id = (unsigned long long)&className##vtblObj,

#define OVERRIDES_END(className) \
    }                            \
    ;

#define COPY_VTBL(className) \
    .interfaces = className##vtblObj,

#define DEF_OBJ(className, objName) \
    struct className objName = {    \
        COPY_VTBL(className)}
