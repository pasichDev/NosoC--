#ifndef COMPILER_H
#define COMPILER_H

#if defined(_MSC_VER)
// Microsoft Visual Studio compiler
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#define DEPRECATED __declspec(deprecated)
#elif defined(__GNUC__)
// GCC and Clang
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#define DEPRECATED __attribute__((deprecated))
#else
// Unknown compiler
#define EXPORT
#define IMPORT
#define DEPRECATED
#endif

#endif // COMPILER_H
