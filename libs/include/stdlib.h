#ifndef _STDLIB_H
#define _STDLIB_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct { int quot; int rem; } div_t;
typedef struct { long quot; long rem; } ldiv_t;
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define RAND_MAX 0x7fffffff
#define MB_CUR_MAX 1
void* malloc(size_t);
void* calloc(size_t, size_t);
void* realloc(void*, size_t);
void free(void*);
void abort(void);
void exit(int);
int atexit(void (*)(void));
char* getenv(const char*);
int system(const char*);
int atoi(const char*);
long atol(const char*);
double atof(const char*);
double strtod(const char*, char**);
long strtol(const char*, char**, int);
unsigned long strtoul(const char*, char**, int);
int rand(void);
void srand(unsigned int);
int abs(int);
long labs(long);
div_t div(int, int);
ldiv_t ldiv(long, long);
void qsort(void*, size_t, size_t, int (*)(const void*, const void*));
void* bsearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));
int mblen(const char*, size_t);
int mbtowc(wchar_t*, const char*, size_t);
int wctomb(char*, wchar_t);
size_t mbstowcs(wchar_t*, const char*, size_t);
size_t wcstombs(char*, const wchar_t*, size_t);
#ifdef __cplusplus
}
#endif
#endif
