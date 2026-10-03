#ifndef _STDDEF_H
#define _STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif
#ifndef NULL
#define NULL 0
#endif
#define offsetof(type, member) ((size_t) & ((type*)0)->member)
#endif
