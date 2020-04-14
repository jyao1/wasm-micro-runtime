/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "platform_api_vmcore.h"
#include "platform_internal.h"
#include <Library/MemoryAllocationLib.h>
#include <Base.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseLib.h>

typedef UINTN  size_t;

int
bh_platform_init()
{
    return 0;
}

void
bh_platform_destroy()
{
}

void *
os_malloc(unsigned size)
{
    return AllocateZeroPool (size);
}

void *
os_realloc(void *ptr, unsigned size)
{
    return NULL;
}

void
os_free(void *ptr)
{
     FreePool (ptr);
}

uint64
os_time_get_boot_microsecond()
{
#if 0
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        return 0;
    }

    return ((uint64) ts.tv_sec) * 1000 * 1000 + ((uint64)ts.tv_nsec) / 1000;
#endif
    return 0;
}


int os_mutex_init(korp_mutex *mutex)
{
    return 0;
}

int os_mutex_destroy(korp_mutex *mutex)
{
    return 0;
}

korp_tid os_self_thread()
{
    return 0;
}


/* Returned error (EINVAL, EAGAIN and EDEADLK) from
 locking the mutex indicates some logic error present in
 the program somewhere.
 Don't try to recover error for an existing unknown error.*/
void os_mutex_lock(korp_mutex *mutex)
{
    return;
}

/* Returned error (EINVAL, EAGAIN and EPERM) from
 unlocking the mutex indicates some logic error present
 in the program somewhere.
 Don't try to recover error for an existing unknown error.*/
void os_mutex_unlock(korp_mutex *mutex)
{
    return;
}




char *strchr(const char *str, int ch)
{
  return ScanMem8 (str, AsciiStrSize (str), (UINT8)ch);
}

/* Scan a string for the last occurrence of a character */
char *strrchr (const char *str, int c)
{
  char * save;

  for (save = NULL; ; ++str) {
    if (*str == c) {
      save = (char *)str;
    }
    if (*str == 0) {
      return (save);
    }
  }
}

int strncasecmp (const char *s1, const char *s2, size_t n)
{
  int Val;

  ASSERT(s1 != NULL);
  ASSERT(s2 != NULL);

  if (n != 0) {
    do {
      Val = tolower(*s1) - tolower(*s2);
      if (Val != 0) {
        return Val;
      }
      ++s1;
      ++s2;
      if (*s1 == '\0') {
        break;
      }
    } while (--n != 0);
  }
  return 0;
}

int sscanf (const char *buffer, const char *format, ...)
{
  //
  // Null sscanf() function implementation to satisfy the linker, since
  // no direct functionality logic dependency in present UEFI cases.
  //
  return 0;
}

/* Maps errnum to an error-message string */
char * strerror (int errnum)
{
  return NULL;
}

size_t strspn (const char *s1 , const char *s2)
{
  UINT8   Map[32];
  UINT32  Index;
  size_t  Count;

  for (Index = 0; Index < 32; Index++) {
    Map[Index] = 0;
  }

  while (*s2) {
    Map[*s2 >> 3] |= (1 << (*s2 & 7));
    s2++;
  }

  if (*s1) {
    Count = 0;
    while (Map[*s1 >> 3] & (1 << (*s1 & 7))) {
      Count++;
      s1++;
    }

    return Count;
  }

  return 0;
}

size_t strcspn (const char *s1, const char *s2)
{
  UINT8  Map[32];
  UINT32 Index;
  size_t Count;

  for (Index = 0; Index < 32; Index++) {
    Map[Index] = 0;
  }

  while (*s2) {
    Map[*s2 >> 3] |= (1 << (*s2 & 7));
    s2++;
  }

  Map[0] |= 1;

  Count   = 0;
  while (!(Map[*s1 >> 3] & (1 << (*s1 & 7)))) {
    Count ++;
    s1++;
  }

  return Count;
}

int isdigit (int c)
{
  //
  // <digit> ::= [0-9]
  //
  return (('0' <= (c)) && ((c) <= '9'));
}

/* Determine if an integer represents character that is a hex digit */
int isxdigit (int c)
{
  //
  // <hexdigit> ::= [0-9] | [a-f] | [A-F]
  //
  return ((('0' <= (c)) && ((c) <= '9')) ||
          (('a' <= (c)) && ((c) <= 'f')) ||
          (('A' <= (c)) && ((c) <= 'F')));
}

int isspace (int c)
{
  //
  // <space> ::= [ ]
  //
  return ((c) == ' ');
}

/* Determine if a particular character is an alphanumeric character */
int isalnum (int c)
{
  //
  // <alnum> ::= [0-9] | [a-z] | [A-Z]
  //
  return ((('0' <= (c)) && ((c) <= '9')) ||
          (('a' <= (c)) && ((c) <= 'z')) ||
          (('A' <= (c)) && ((c) <= 'Z')));
}

int isupper (int c)
{
  //
  // <uppercase letter> := [A-Z]
  //
  return (('A' <= (c)) && ((c) <= 'Z'));
}

//
// -- Data Conversion Routines --
//

/* Convert strings to a long-integer value */
long strtol (const char *nptr, char **endptr, int base)
{
  //
  // Null strtol() function implementation to satisfy the linker, since there is
  // no direct functionality logic dependency in present UEFI cases.
  //
  return 0;
}

unsigned long strtoull (const char *nptr, char **endptr, int base)
{
  //
  // Null strtoul() function implementation to satisfy the linker, since there is
  // no direct functionality logic dependency in present UEFI cases.
  //
  return 0;
}

unsigned long int strtoul (const char *nptr, char **endptr, int base)
{
  //
  // Null strtoul() function implementation to satisfy the linker, since there is
  // no direct functionality logic dependency in present UEFI cases.
  //
  return 0;
}

float          strtof      (const char * str, char ** str_end)
{
  return 0;
}

double         strtod      (const char * str, char ** str_end)
{
  return 0;
}

double sqrt(double x)
{ 
  return 0; 
}

double floor(double x)
{ 
  return 0; 
}

double ceil(double x)
{ 
  return 0; 
}

double fmin(double x, double y)
{ 
  return 0; 
}

double fmax(double x, double y)
{ 
  return 0; 
}

double rint(double x)
{ 
  return 0; 
}

double fabs(double x)
{ 
  return 0; 
}

double trunc(double x)
{ 
  return 0; 
}

float floorf(float x)
{ 
  return 0; 
}

float ceilf(float x)
{ 
  return 0; 
}

float fminf(float x, float y)
{ 
  return 0; 
}

float fmaxf(float x, float y)
{ 
  return 0; 
}

float rintf(float x)
{ 
  return 0; 
}

float truncf(float x)
{ 
  return 0; 
}

int signbit(double x)
{ 
  return 0; 
}

int isnan(double x)
{ 
  return 0; 
}


int            isalpha     (int c)
{
  return 0; 
}

int            isgraph     (int c)
{
  return 0; 
}

int            isprint     (int c) 
{
  return 0; 
}

int            toupper     (int c)
{
  return 0; 
}



/* Convert character to lowercase */
int tolower (int c)
{
  if (('A' <= (c)) && ((c) <= 'Z')) {
    return (c - ('A' - 'a'));
  }
  return (c);
}


void abort (void)
{
  // Do nothing
}

int fclose (FILE *f)
{
  return 0;
}

FILE *fopen (const char *c, const char *m)
{
  return NULL;
}

size_t fread (void *b, size_t c, size_t i, FILE *f)
{
  return 0;
}

char*
bh_read_file_to_buffer(const char *filename, uint32 *ret_size)
{
  return NULL;
}

#define MAX_DEBUG_MESSAGE_LENGTH  0x100

VOID
PatchFormat (
  IN  CONST CHAR8  *Format,
  IN OUT    CHAR8  *MyFormat
  )
{
  UINTN  Index;
  UINTN  MyIndex;

  Index = 0;
  MyIndex = 0;
  while (Format[Index] != 0) {
    MyFormat[MyIndex] = Format[Index];
    if (Format[Index] == '%') {
      Index++;
      MyIndex++;
      switch (Format[Index]) {
      case 's':
        MyFormat[MyIndex] = 'a';
        break;
      case 'z':
        if (Format[Index + 1] == 'u') {
          Index++;
          MyFormat[MyIndex] = 'd';
        }
        break;
      default:
        MyFormat[MyIndex] = Format[Index];
        break;
      }
    }
    Index++;
    MyIndex++;
  }
  MyFormat[MyIndex] = 0;
}

/**
  Worker function that convert a VA_LIST to a BASE_LIST based on a
  Null-terminated format string.

  @param  Format          Null-terminated format string.
  @param  VaListMarker    VA_LIST style variable argument list consumed
                          by processing Format.
  @param  BaseListMarker  BASE_LIST style variable argument list consumed
                          by processing Format.
  @param  Size            The size, in bytes, of the BaseListMarker buffer.

  @return TRUE   The VA_LIST has been converted to BASE_LIST.
  @return FALSE  The VA_LIST has not been converted to BASE_LIST.

**/
BOOLEAN
VaListToBaseList (
  IN  CONST CHAR8  *Format,
  IN  VA_LIST      VaListMarker,
  OUT BASE_LIST    BaseListMarker,
  IN  UINTN        Size
  )
{
  BASE_LIST       BaseListStart;
  BOOLEAN         Long;

  ASSERT (Format != NULL);

  ASSERT (BaseListMarker != NULL);

  BaseListStart = BaseListMarker;

  for (; *Format != '\0'; Format++) {
    //
    // Only format with prefix % is processed.
    //
    if (*Format != '%') {
      continue;
    }

    Long = FALSE;

    //
    // Parse Flags and Width
    //
    for (Format++; TRUE; Format++) {
      if (*Format == '.' || *Format == '-' || *Format == '+' || *Format == ' ') {
        //
        // These characters in format field are omitted.
        //
        continue;
      }
      if (*Format >= '0' && *Format <= '9') {
        //
        // These characters in format field are omitted.
        //
        continue;
      }
      if (*Format == 'L' || *Format == 'l') {
        //
        // 'L" or "l" in format field means the number being printed is a UINT64
        //
        Long = TRUE;
        continue;
      }
      if (*Format == '*') {
        //
        // '*' in format field means the precision of the field is specified by
        // a UINTN argument in the argument list.
        //
        BASE_ARG (BaseListMarker, UINTN) = VA_ARG (VaListMarker, UINTN);
        continue;
      }
      if (*Format == '\0') {
        //
        // Make no output if Format string terminates unexpectedly when
        // looking up for flag, width, precision and type.
        //
        Format--;
      }
      //
      // When valid argument type detected or format string terminates unexpectedly,
      // the inner loop is done.
      //
      break;
    }

    //
    // Pack variable arguments into the storage area following EFI_DEBUG_INFO.
    //
    if ((*Format == 'p') && (sizeof (VOID *) > 4)) {
      Long = TRUE;
    }
    if (*Format == 'p' || *Format == 'X' || *Format == 'x' || *Format == 'd' || *Format == 'u') {
      if (Long) {
        BASE_ARG (BaseListMarker, INT64) = VA_ARG (VaListMarker, INT64);
      } else {
        BASE_ARG (BaseListMarker, int) = VA_ARG (VaListMarker, int);
      }
    } else if (*Format == 's' || *Format == 'S' || *Format == 'a' || *Format == 'g' || *Format == 't') {
      BASE_ARG (BaseListMarker, VOID *) = VA_ARG (VaListMarker, VOID *);
    } else if (*Format == 'c') {
      BASE_ARG (BaseListMarker, UINTN) = VA_ARG (VaListMarker, UINTN);
    } else if (*Format == 'r') {
      BASE_ARG (BaseListMarker, RETURN_STATUS) = VA_ARG (VaListMarker, RETURN_STATUS);
    }

    //
    // If the converted BASE_LIST is larger than the size of BaseListMarker, then return FALSE
    //
    if (((UINTN)BaseListMarker - (UINTN)BaseListStart) > Size) {
      return FALSE;
    }
  }

  return TRUE;
}

int os_printf(const char *format, ...)
{
  UINT64  BaseListMarker[256 / sizeof (UINT64)];
  VA_LIST Marker;
  CHAR8   MyFormat[MAX_DEBUG_MESSAGE_LENGTH];
  CHAR8   MyBuffer[MAX_DEBUG_MESSAGE_LENGTH];
  
  PatchFormat (format, MyFormat);

  VA_START (Marker, format);
  VaListToBaseList (
                MyFormat,
                Marker,
                (BASE_LIST)BaseListMarker,
                sizeof (BaseListMarker) - 8
                );
  VA_END (Marker);

  AsciiBSPrint (MyBuffer, sizeof(MyBuffer), MyFormat, BaseListMarker);
  DebugPrint (DEBUG_INFO, "%a", MyBuffer);
  AsciiPrint ("%a", MyBuffer);
  
  return 1;
}

int os_vprintf(const char *format, va_list ap)
{
  return 0;
}


int snprintf(char *str, size_t size, const char *format, ...)
{
  return 0;
}

uint64 bh_get_tick_ms()
{
    return os_time_get_boot_microsecond() / 1000;
}

#if 0
void * memcpy (void *dest, const void *src, unsigned int count)
{
  return CopyMem (dest, src, (UINTN)count);
}

/* Sets buffers to a specified character */
void * memset (void *dest, int ch, size_t count)
{
  //
  // NOTE: Here we use one base implementation for memset, instead of the direct
  //       optimized SetMem() wrapper. Because the IntrinsicLib has to be built
  //       without whole program optimization option, and there will be some
  //       potential register usage errors when calling other optimized codes.
  //

  //
  // Declare the local variables that actually move the data elements as
  // volatile to prevent the optimizer from replacing this function with
  // the intrinsic memset()
  //
  volatile UINT8  *Pointer;

  Pointer = (UINT8 *)dest;
  while (count-- != 0) {
    *(Pointer++) = (UINT8)ch;
  }

  return dest;
}


/* Compare bytes in two buffers. */
int memcmp (const void *buf1, const void *buf2, size_t count)
{
  return (int)CompareMem(buf1, buf2, count);
}

int strcmp (const char *s1, const char *s2)
{
  return (int)AsciiStrCmp(s1, s2);
}
#endif

char *strstr(const char *haystack, const char *needle)
{
  return NULL;
}






