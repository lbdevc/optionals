//
//  optionals.h
//  optionals
//
//  Created by lbdevc on 08/03/2021.
//

#ifndef __optionals_h__
#define __optionals_h__

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>

typedef enum {
	none, some
} Optional;

#define OPTIONALS_USE(T) \
typedef struct { \
Optional optional; \
T value; \
} Optional##T; \
Optional##T makeOptional##T() { \
Optional##T __optional; \
__optional.optional = none; \
return __optional; \
} \
Optional##T makeOptional##T##WithValue(T value) { \
Optional##T __optional; \
__optional.optional = some; \
__optional.value = value; \
return __optional; \
} \
T unsafelyUnwrapped##T(Optional##T optional) { \
switch (optional.optional) { \
case some: \
return optional.value; \
break; \
default: \
printf("unsafelyUnWrapped of nil optional\n"); \
exit(EXIT_FAILURE); \
break; \
} \
} \
Bool unwrapped##T(Optional##T optional, T * into) { \
switch (optional.optional) { \
case some: \
*into = optional.value; \
return true; \
default: \
return false; \
break; \
} \
} \

typedef float Float;
typedef int Int;
typedef unsigned UInt;
typedef double Double;
typedef float Float;
typedef char Character;

typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;

typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;

typedef enum {
	false = 0,
	true = !false
} Bool;

OPTIONALS_USE(Int)
OPTIONALS_USE(UInt)
OPTIONALS_USE(Double)
OPTIONALS_USE(Float)
OPTIONALS_USE(Character)

OPTIONALS_USE(Int8)
OPTIONALS_USE(Int16)
OPTIONALS_USE(Int32)
OPTIONALS_USE(Int64)

OPTIONALS_USE(UInt8)
OPTIONALS_USE(UInt16)
OPTIONALS_USE(UInt32)
OPTIONALS_USE(UInt64)

OPTIONALS_USE(Bool)
	
#ifdef __cplusplus
} /* extern "C" { */
#endif
		
#endif /* __optionals_h__ */
