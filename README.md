# optionals
A C implementation of Swift's optionals

# Usage

## Including in your project

This is a single header solution, so add the optionals.h to your project and `#include "optionals.h"`

## Creating optionals

As ANSI C does not support templates you will have to use the macro `OPTIONALS_USE(T)` where T : type for the type you want to use. For convenience C's primitive types have already been defined using the Swift stdlib naming scheme.

```c
OPTIONALS_USE(Int) // int
OPTIONALS_USE(UInt) // unsigned
OPTIONALS_USE(Double) // double
OPTIONALS_USE(Float) // float
OPTIONALS_USE(Character) // char
OPTIONALS_USE(Int8) // int8_t
OPTIONALS_USE(Int16) // int16_t
OPTIONALS_USE(Int32) // int32_t
OPTIONALS_USE(Int64) // int64_t
OPTIONALS_USE(UInt8) // uint8_t
OPTIONALS_USE(UInt16) // uint16_t
OPTIONALS_USE(UInt32) // uint32_t
OPTIONALS_USE(UInt64) // uint64_t
OPTIONALS_USE(Bool) // can be used where _Bool is used
```

You can create an optional using the Optional##T type, where ##T : typename.

```c
OptionalCustomStruct myOptional;
```

Given we typedef'd struct CustomStruct, initialize the optional with either:

```c
typedef struct {} CustomStruct;
OPTIONALS_USE(CustomStruct)

OptionalCustomStruct myOptional = makeOptionalCustomStruct(); // Optional is nil
```

or 

```c
OptionalCustomStruct myOptional = makeOptionalCustomStructWithValue(CustomStruct value); // Optional has the value "value"
```

To unwrap an optional value, make a pointer to hold your unwrapped value and pass it to unwrapped##T(optional, * into) where ##T is your type. 
unwrapped##T will return true if the optional had a value, and will store the value att the adress of the provided pointer.

```c
Int * myUnwrapped; // equivalent to int * myUnwrapped 

if (unwrappedInt(myOptional, &myUnwrapped)) // do stuff
```

If you're sure that your optional contains a value you can force unwrap it to save performance.

```c
Int myUnwrapped;

myUnwrapped = unsafelyUnwrappedInt(myNonNilOptional);
```
