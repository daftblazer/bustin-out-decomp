#ifndef _STDIO_H
#define _STDIO_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct __FILE FILE;
typedef long fpos_t;
#define EOF (-1)
#define BUFSIZ 1024
#define FILENAME_MAX 256
#define FOPEN_MAX 20
#define L_tmpnam 256
#define TMP_MAX 32
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;
typedef char* __va_list_stdio;
int printf(const char*, ...);
int sprintf(char*, const char*, ...);
int fprintf(FILE*, const char*, ...);
int sscanf(const char*, const char*, ...);
int scanf(const char*, ...);
int fscanf(FILE*, const char*, ...);
int vprintf(const char*, __va_list_stdio);
int vsprintf(char*, const char*, __va_list_stdio);
int vfprintf(FILE*, const char*, __va_list_stdio);
FILE* fopen(const char*, const char*);
FILE* freopen(const char*, const char*, FILE*);
int fclose(FILE*);
int fflush(FILE*);
size_t fread(void*, size_t, size_t, FILE*);
size_t fwrite(const void*, size_t, size_t, FILE*);
int fseek(FILE*, long, int);
long ftell(FILE*);
void rewind(FILE*);
int fgetpos(FILE*, fpos_t*);
int fsetpos(FILE*, const fpos_t*);
int fgetc(FILE*);
int fputc(int, FILE*);
char* fgets(char*, int, FILE*);
int fputs(const char*, FILE*);
int getc(FILE*);
int putc(int, FILE*);
int getchar(void);
int putchar(int);
char* gets(char*);
int puts(const char*);
int ungetc(int, FILE*);
int feof(FILE*);
int ferror(FILE*);
void clearerr(FILE*);
void perror(const char*);
int remove(const char*);
int rename(const char*, const char*);
FILE* tmpfile(void);
char* tmpnam(char*);
void setbuf(FILE*, char*);
int setvbuf(FILE*, char*, int, size_t);
#ifdef __cplusplus
}
#endif
#endif
