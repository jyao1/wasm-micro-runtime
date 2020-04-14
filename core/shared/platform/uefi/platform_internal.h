/** @file
  Root include file of C runtime library to support building the third-party
  cryptographic library.

Copyright (c) 2010 - 2019, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/
#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <Uefi.h>

#include <Protocol/SimpleFileSystem.h>
#include <Protocol/LoadedImage.h>

#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DevicePathLib.h>
#include <Library/PcdLib.h>
#include <Library/FileHandleLib.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiLib.h>

#if defined(_MSC_EXTENSIONS)
typedef INTN __INTPTR_TYPE__;
typedef UINTN __UINTPTR_TYPE__;
#endif

typedef UINTN size_t;
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BH_PLATFORM_UEFI
#define BH_PLATFORM_UEFI
#endif

typedef INT16 korp_tid;
typedef INT16 korp_mutex;
typedef INT16 korp_cond;
typedef INT16 korp_thread;

#ifdef __cplusplus
}
#endif

#define va_list   VA_LIST
#define va_start  VA_START
#define va_end    VA_END

typedef BOOLEAN        bool;

#define MAX_STRING_SIZE  0x1000

// File operations are not required for EFI building,
// so FILE is mapped to VOID * to pass build
//
typedef VOID  *FILE;

//
// Global variables
//
extern int  errno;
extern FILE *stderr;


//
// Function prototypes of CRT Library routines
//
//void           *malloc     (size_t);
//void           *realloc    (void *, size_t);
//void           free        (void *);
void           *memset     (void *, int, size_t);
int            memcmp      (const void *, const void *, size_t);
int            isdigit     (int);
int            isspace     (int);
int            isxdigit    (int);
int            isalnum     (int);
int            isupper     (int);
int            tolower     (int);
int            strcmp      (const char *, const char *);
char *         strstr(const char *haystack, const char *needle);
int            strncasecmp (const char *, const char *, size_t);
char           *strchr     (const char *, int);
char           *strrchr    (const char *, int);
unsigned long  strtoull    (const char *, char **, int);
unsigned long int strtoul (const char *nptr, char **endptr, int base);
long           strtol      (const char *, char **, int);
float          strtof      (const char * str, char ** str_end);
double         strtod      (const char * str, char ** str_end);
char           *strerror   (int);
//bool           isnan      (int x);
size_t         strspn      (const char *, const char *);
size_t         strcspn     (const char *, const char *);
//int            printf      (const char *, ...);
int            sscanf      (const char *, const char *, ...);
FILE           *fopen      (const char *, const char *);
size_t         fread       (void *, size_t, size_t, FILE *);
size_t         fwrite      (const void *, size_t, size_t, FILE *);
int            fclose      (FILE *);
int            fprintf     (FILE *, const char *, ...);
int            snprintf    (char *str, size_t size, const char *format, ...);
double sqrt(double x);
double floor(double x);
double ceil(double x);
double fmin(double x, double y);
double fmax(double x, double y);
double rint(double x);
double fabs(double x);
double trunc(double x);
float floorf(float x);
float ceilf(float x);
float fminf(float x, float y);
float fmaxf(float x, float y);
float rintf(float x);
float truncf(float x);
int signbit(double x);
int isnan(double x);

int            isalpha     (int);
int            isgraph     (int);
int            isprint     (int); 
int            toupper     (int);
void * memcpy (void *dest, const void *src, unsigned int count);
void * memset (void *dest, int ch, size_t count);
int memcmp (const void *buf1, const void *buf2, size_t count);

//
// Macros that directly map functions to BaseLib, BaseMemoryLib, and DebugLib functions
//
//#define memcpy(dest,source,count)         CopyMem(dest,source,(UINTN)(count))
//#define memset(dest,ch,count)             SetMem(dest,(UINTN)(count),(UINT8)(ch))
#define memchr(buf,ch,count)              ScanMem8(buf,(UINTN)(count),(UINT8)ch)
//#define memcmp(buf1,buf2,count)           (int)(CompareMem(buf1,buf2,(UINTN)(count)))
#define memmove(dest,source,count)        CopyMem(dest,source,(UINTN)(count))
#define strlen(str)                       (size_t)(AsciiStrnLenS(str,MAX_STRING_SIZE))
#define strcpy(strDest,strSource)         AsciiStrCpyS(strDest,MAX_STRING_SIZE,strSource)
#define strncpy(strDest,strSource,count)  AsciiStrnCpyS(strDest,MAX_STRING_SIZE,strSource,(UINTN)count)
#define strcat(strDest,strSource)         AsciiStrCatS(strDest,MAX_STRING_SIZE,strSource)
#define strncmp(string1,string2,count)    (int)(AsciiStrnCmp(string1,string2,(UINTN)(count)))
#define strcasecmp(str1,str2)             (int)AsciiStriCmp(str1,str2)
#define sprintf(buf,...)                  AsciiSPrint(buf,MAX_STRING_SIZE,__VA_ARGS__)
//#define printf                            print
#define assert(expression)
#define offsetof(type,member)             OFFSET_OF(type,member)
#define atoi(nptr)                        AsciiStrDecimalToUintn(nptr)

#endif
