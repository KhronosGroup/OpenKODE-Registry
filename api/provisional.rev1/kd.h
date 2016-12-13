/* Sample KD/kd.h for OpenKODE Core 1.0 Provisional revision 1 */
#ifndef __kd_h_
#define __kd_h_

#ifdef __cplusplus
extern "C" {
#endif

#include <EGL/egl.h>
#include "kdplatform.h"



/*******************************************************
 * Introduction
 *******************************************************/

/*******************************************************
 * OpenKODE conformance
 *******************************************************/

/*******************************************************
 * Overview
 *******************************************************/

/*******************************************************
 * Programming environment
 *******************************************************/
typedef char KDchar;
typedef signed char KDint8;
typedef unsigned char KDuint8;
typedef int KDint;
typedef unsigned int KDuint;
typedef KDuint32 KDsocklen;
typedef float KDfloat32;
typedef KDint KDboolean;
typedef KDint64 KDtime;
typedef KDint64 KDust;
typedef KDint64 KDoff;
typedef KDuint32 KDmode;
#define KDINT32_MIN (-0x7fffffff-1)
#define KDINT32_MAX 0x7fffffff
#define KDUINT32_MAX 0xffffffffU
#define KD_TRUE 1
#define KD_FALSE 0
#define KD_NULL ((void *)0)

/*******************************************************
 * Errors
 *******************************************************/
#define KD_EACCES (13)
#define KD_EADDRINUSE (98)
#define KD_EADDRNOTAVAIL (99)
#define KD_EAFNOSUPPORT (97)
#define KD_EAGAIN (11)
#define KD_EALREADY (114)
#define KD_EBADF (9)
#define KD_EBUSY (16)
#define KD_ECONNREFUSED (111)
#define KD_ECONNRESET (104)
#define KD_EDESTADDRREQ (89)
#define KD_EDOM (33)
#define KD_ERANGE (34)
#define KD_EEXIST (17)
#define KD_EFBIG (27)
#define KD_EHOSTUNREACH (113)
#define KD_EINVAL (22)
#define KD_EIO (5)
#define KD_EILSEQ (84)
#define KD_EISCONN (106)
#define KD_EISDIR (21)
#define KD_EMFILE (24)
#define KD_ENAMETOOLONG (36)
#define KD_ENOENT (2)
#define KD_ENOMEM (12)
#define KD_ENOSPC (28)
#define KD_ENOSYS (38)
#define KD_ENOTCONN (107)
#define KD_EOPNOTSUPP (95)
#define KD_EOVERFLOW (75)
#define KD_EPERM (1)
#define KD_EPIPE (32)
#define KD_ERANGE (34)
#define KD_ETIMEDOUT (110)

/* kdGetError: Get last error indication. */
KD_API KDint KD_APIENTRY kdGetError(void);

/* kdSetError: Set last error indication. */
KD_API void KD_APIENTRY kdSetError(KDint error);

/*******************************************************
 * Versioning and attribute queries
 *******************************************************/

/* kdQueryAttribi: Obtain the value of a numeric OpenKODE Core attribute. */
KD_API KDint KD_APIENTRY kdQueryAttribi(KDint attribute, KDint *value);
#define KD_ATTRIB_NUM_EXTENSIONS 0

/* kdQueryAttribcv: Obtain the value of a string OpenKODE Core attribute. */
KD_API const KDchar *KD_APIENTRY kdQueryAttribcv(KDint attribute);
#define KD_ATTRIB_VENDOR 0
#define KD_ATTRIB_VERSION 1

/* kdQueryIndexedAttribcv: Obtain the value of an indexed string OpenKODE Core attribute. */
KD_API const KDchar *KD_APIENTRY kdQueryIndexedAttribcv(KDint attribute, KDint index);
#define KD_ATTRIB_EXTENSIONS 0

/* kdGetProcAddress: Get the address of an extension function. */
KD_API void *KD_APIENTRY kdGetProcAddress(const KDchar *name);

/*******************************************************
 * Events
 *******************************************************/

/* KDEvent: Struct type containing an event. */
typedef struct KDEvent KDEvent;
#define KD_EVENT_USER 0x100000

/* kdWaitEvent: Get next event from queue. */
KD_API const KDEvent *KD_APIENTRY kdWaitEvent(KDust timeout);

/* kdSetEventUserptr: Set the userptr for global events. */
KD_API void KD_APIENTRY kdSetEventUserptr(void *userptr);

/* kdDefaultEvent: Perform default processing on an unrecognized event. */
KD_API void KD_APIENTRY kdDefaultEvent(const KDEvent *event);

/* kdPumpEvents: Pump the event queue, performing callbacks. */
KD_API KDint KD_APIENTRY kdPumpEvents(void);

/* kdInstallCallback: Install or remove a callback function for event processing. */
typedef void (KD_APIENTRY KDCallbackFunc)(const KDEvent *event);
KD_API KDint KD_APIENTRY kdInstallCallback(KDCallbackFunc *func, KDint eventtype, void *eventuserptr);

/* kdCreateEvent: Create an event for posting. */
KD_API KDEvent *KD_APIENTRY kdCreateEvent(void);

/* kdPostEvent: Post an event into the queue. */
KD_API KDint KD_APIENTRY kdPostEvent(KDEvent *event);
typedef struct KDEventUser {
    union {
        KDint64 i64;
        void *p;
        struct {
            KDint32 a;
            KDint32 b;
        } i32pair;
    } value1;
    union {
        KDint64 i64;
        struct {
            union {
                KDint32 i32;
                void *p;
            } value2;
            union {
                KDint32 i32;
                void *p;
            } value3;
        } i32orp;
    } value23;
} KDEventUser;

/* kdFreeEvent: Abandon an event instead of posting it. */
KD_API void KD_APIENTRY kdFreeEvent(KDEvent *event);

/*******************************************************
 * System events
 *******************************************************/

/* KD_EVENT_QUIT: Event to request to quit application. */
#define KD_EVENT_QUIT 1

/* KD_EVENT_PAUSE: Application pause event. */
#define KD_EVENT_PAUSE 3

/* KD_EVENT_RESUME: Application resume event. */
#define KD_EVENT_RESUME 4

/* KD_IOGROUP_EVENT: I/O group for OpenKODE Core system events implemented as inputs. */
#define KD_IOGROUP_EVENT 0x100
#define KD_IO_EVENT_USING_BATTERY       (KD_IOGROUP_EVENT + 0)
#define KD_IO_EVENT_LOW_BATTERY         (KD_IOGROUP_EVENT + 1)


/*******************************************************
 * Application startup and exit.
 *******************************************************/

/* kdMain: The application-defined main function. */
KD_API KDint KD_APIENTRY kdMain(KDint argc, const KDchar **argv);

/* kdExit: Exit the application. */
KD_API void KD_APIENTRY kdExit(KDint status);

/*******************************************************
 * Utility library functions
 *******************************************************/

/* kdAbs: Compute the absolute value of an integer. */
KD_API KDint KD_APIENTRY kdAbs(KDint i);

/* kdStrtof: Convert a string to a floating point number. */
KD_API KDfloat32 KD_APIENTRY kdStrtof(const KDchar *s, KDchar **endptr);

/* kdStrtol, kdStrtoul: Convert a string to an integer. */
KD_API KDint KD_APIENTRY kdStrtol(const KDchar *s, KDchar **endptr, KDint base);
KD_API KDuint KD_APIENTRY kdStrtoul(const KDchar *s, KDchar **endptr, KDint base);

/* kdLtostr, kdUltostr: Convert an integer to a string. */
#define KD_LTOSTR_MAXLEN ((sizeof(KDint)*8*3+6)/10+2)
#define KD_ULTOSTR_MAXLEN ((sizeof(KDint)*8*3+9)/10+1)
KD_API KDssize KD_APIENTRY kdLtostr(KDchar *buffer, KDsize buflen, KDint number);
KD_API KDssize KD_APIENTRY kdUltostr(KDchar *buffer, KDsize buflen, KDuint number, KDint radix);

/* kdFtostr: Convert a float to a string. */
#define KD_FTOSTR_MAXLEN 16
KD_API KDssize KD_APIENTRY kdFtostr(KDchar *buffer, KDsize buflen, KDfloat32 number);

/* kdCryptoRandom: Return random data. */
KD_API KDint KD_APIENTRY kdCryptoRandom(KDuint8 *buf, KDsize buflen);

/*******************************************************
 * Locale specific functions
 *******************************************************/

/* kdGetLocale: Determine the current language and locale. */
KD_API const KDchar *KD_APIENTRY kdGetLocale(void);

/* kdGetTzOffset: Return the timezone offset. */
KD_API KDint KD_APIENTRY kdGetTzOffset(void);

/*******************************************************
 * Memory allocation
 *******************************************************/

/* kdMalloc: Allocate memory. */
KD_API void *KD_APIENTRY kdMalloc(KDsize size);

/* kdFree: Free allocated memory block. */
KD_API void KD_APIENTRY kdFree(void *ptr);

/* kdRealloc: Resize memory block. */
KD_API void *KD_APIENTRY kdRealloc(void *ptr, KDsize size);

/*******************************************************
 * Thread-local storage.
 *******************************************************/

/* kdGetTLS: Get the thread-local storage pointer. */
KD_API void *KD_APIENTRY kdGetTLS(void);

/* kdSetTLS: Set the thread-local storage pointer. */
KD_API void KD_APIENTRY kdSetTLS(void *ptr);

/*******************************************************
 * Mathematical functions
 *******************************************************/
#define KD_E_F 2.71828175F
#define KD_PI_F 3.14159274F
#define KD_PI_2_F 1.57079637F
#define KD_2PI_F 6.28318548F
#define KD_LOG2E_F 1.44269502F
#define KD_LOG10E_F 0.434294492F
#define KD_LN2_F 0.693147182F
#define KD_LN10_F 2.30258512F
#define KD_PI_4_F 0.785398185F
#define KD_1_PI_F 0.318309873F
#define KD_2_PI_F 0.636619747F
#define KD_2_SQRTPI_F 1.12837923F
#define KD_SQRT2_F 1.41421354F
#define KD_SQRT1_2_F 0.707106769F
#define KD_MAXFLOAT 3.40282347e+38F
#define KD_INFINITY (1.0F/0.0F)
#define KD_NAN (0.0F/0.0F)
#define KD_HUGE_VALF (1.0F/0.0F)
#define KD_DEG_TO_RAD_F 0.0174532924F
#define KD_RAD_TO_DEG_F 57.2957802F

/* kdAcosf: Arc cosine function. */
KD_API KDfloat32 KD_APIENTRY kdAcosf(KDfloat32 x);

/* kdAsinf: Arc sine function. */
KD_API KDfloat32 KD_APIENTRY kdAsinf(KDfloat32 x);

/* kdAtanf: Arc tangent function. */
KD_API KDfloat32 KD_APIENTRY kdAtanf(KDfloat32 x);

/* kdAtan2f: Arc tangent function. */
KD_API KDfloat32 KD_APIENTRY kdAtan2f(KDfloat32 y, KDfloat32 x);

/* kdCosf: Cosine function. */
KD_API KDfloat32 KD_APIENTRY kdCosf(KDfloat32 x);

/* kdSinf: Sine function. */
KD_API KDfloat32 KD_APIENTRY kdSinf(KDfloat32 x);

/* kdTanf: Tangent function. */
KD_API KDfloat32 KD_APIENTRY kdTanf(KDfloat32 x);

/* kdExpf: Exponential function. */
KD_API KDfloat32 KD_APIENTRY kdExpf(KDfloat32 x);

/* kdLogf: Natural logarithm function. */
KD_API KDfloat32 KD_APIENTRY kdLogf(KDfloat32 x);

/* kdFabsf: Absolute value. */
KD_API KDfloat32 KD_APIENTRY kdFabsf(KDfloat32 x);

/* kdPowf: Power function. */
KD_API KDfloat32 KD_APIENTRY kdPowf(KDfloat32 x, KDfloat32 y);

/* kdSqrtf: Square root function. */
KD_API KDfloat32 KD_APIENTRY kdSqrtf(KDfloat32 x);

/* kdCeilf: Return ceiling value. */
KD_API KDfloat32 KD_APIENTRY kdCeilf(KDfloat32 x);

/* kdFloorf: Return floor value. */
KD_API KDfloat32 KD_APIENTRY kdFloorf(KDfloat32 x);

/* kdRoundf: Round value to nearest integer. */
KD_API KDfloat32 KD_APIENTRY kdRoundf(KDfloat32 x);

/* kdInvsqrtf: Inverse square root function. */
KD_API KDfloat32 KD_APIENTRY kdInvsqrtf(KDfloat32 x);

/* kdFmodf: Calculate floating point remainder. */
KD_API KDfloat32 KD_APIENTRY kdFmodf(KDfloat32 x, KDfloat32 y);

/*******************************************************
 * String and memory functions
 *******************************************************/

/* kdMemchr: Scan memory for a byte value. */
KD_API void *KD_APIENTRY kdMemchr(const void *src, KDint byte, KDsize len);

/* kdMemcmp: Compare two memory regions. */
KD_API KDint KD_APIENTRY kdMemcmp(const void *src1, const void *src2, KDsize len);

/* kdMemcpy: Copy a memory region, no overlapping. */
KD_API void *KD_APIENTRY kdMemcpy(void *buf, const void *src, KDsize len);

/* kdMemmove: Copy a memory region, overlapping allowed. */
KD_API void *KD_APIENTRY kdMemmove(void *buf, const void *src, KDsize len);

/* kdMemset: Set bytes in memory to a value. */
KD_API void *KD_APIENTRY kdMemset(void *buf, KDint byte, KDsize len);

/* kdStrchr: Scan string for a byte value. */
KD_API KDchar *KD_APIENTRY kdStrchr(const KDchar *str, KDint ch);

/* kdStrcmp: Compares two strings. */
KD_API KDint KD_APIENTRY kdStrcmp(const KDchar *str1, const KDchar *str2);

/* kdStrlen: Determine the length of a string. */
KD_API KDsize KD_APIENTRY kdStrlen(const KDchar *str);

/* kdStrnlen: Determine the length of a string. */
KD_API KDsize KD_APIENTRY kdStrnlen(const KDchar *str, KDsize maxlen);

/* kdStrncat_s: Concatenate two strings. */
KD_API KDint KD_APIENTRY kdStrncat_s(KDchar *buf, KDsize buflen, const KDchar *src, KDsize srcmaxlen);

/* kdStrncmp: Compares two strings with length limit. */
KD_API KDint KD_APIENTRY kdStrncmp(const KDchar *str1, const KDchar *str2, KDsize maxlen);

/* kdStrcpy_s: Copy a string with an overrun check. */
KD_API KDint KD_APIENTRY kdStrcpy_s(KDchar *buf, KDsize buflen, const KDchar *s);

/* kdStrncpy_s: Copy a string with an overrun check. */
KD_API KDint KD_APIENTRY kdStrncpy_s(KDchar *buf, KDsize buflen, const KDchar *src, KDsize srclen);

/*******************************************************
 * Time functions
 *******************************************************/

/* kdGetTimeUST: Get the current unadjusted system time. */
KD_API KDust KD_APIENTRY kdGetTimeUST(void);

/* kdTime: Get the current wall clock time. */
KD_API KDtime KD_APIENTRY kdTime(KDtime *timep);

/* kdGmtime_r, kdLocaltime_r: Convert a seconds-since-epoch time into broken-down time. */
typedef struct KDtm {
    KDint32 tm_sec;
    KDint32 tm_min;
    KDint32 tm_hour;
    KDint32 tm_mday;
    KDint32 tm_mon;
    KDint32 tm_year;
    KDint32 tm_wday;
    KDint32 tm_yday;
    KDint32 tm_isdst;
} KDtm;
KD_API KDtm *KD_APIENTRY kdGmtime_r(const KDtime *timep, KDtm *result);
KD_API KDtm *KD_APIENTRY kdLocaltime_r(const KDtime *timep, KDtm *result);

/* kdUSTAtEpoch: Get the UST corresponding to KDtime 0. */
KD_API KDust KD_APIENTRY kdUSTAtEpoch(void);

/*******************************************************
 * Timer functions
 *******************************************************/

/* kdSetTimer: Set timer. */
#define KD_TIMER_ONESHOT 0
#define KD_TIMER_PERIODIC_AVERAGE 1
#define KD_TIMER_PERIODIC_MINIMUM 2
typedef struct KDTimer KDTimer;
KD_API KDTimer *KD_APIENTRY kdSetTimer(KDint64 interval, KDint periodic, void *eventuserptr);

/* kdCancelTimer: Cancel and free a timer. */
KD_API void KD_APIENTRY kdCancelTimer(KDTimer *timer);

/* KD_EVENT_TIMER: Timer fire event. */
#define KD_EVENT_TIMER 0x300

/*******************************************************
 * File system
 *******************************************************/
#define KD_EOF (-1)

/* kdFopen: Open a file from the file system. */
typedef struct KDFile KDFile;
KD_API KDFile *KD_APIENTRY kdFopen(const KDchar *pathname, const KDchar *mode);

/* kdFclose: Close an open file. */
KD_API KDint KD_APIENTRY kdFclose(KDFile *file);

/* kdFflush: Flush an open file. */
KD_API KDint KD_APIENTRY kdFflush(KDFile *file);

/* kdFread: Read from a file. */
KD_API KDsize KD_APIENTRY kdFread(void *buffer, KDsize size, KDsize count, KDFile *file);

/* kdFwrite: Write to a file. */
KD_API KDsize KD_APIENTRY kdFwrite(const void *buffer, KDsize size, KDsize count, KDFile *file);

/* kdGetc: Read next byte from an open file. */
KD_API KDint KD_APIENTRY kdGetc(KDFile *file);

/* kdPutc: Write a byte to an open file. */
KD_API KDint KD_APIENTRY kdPutc(KDchar c, KDFile *file);

/* kdFgets: Read a line of text from an open file. */
KD_API KDchar *KD_APIENTRY kdFgets(KDchar *buffer, KDsize buflen, KDFile *file);

/* kdFEOF: Check for end of file. */
KD_API KDint KD_APIENTRY kdFEOF(KDFile *file);

/* kdFerror: Check for an error condition on an open file. */
KD_API KDint KD_APIENTRY kdFerror(KDFile *file);

/* kdClearerr: Clear a file&#8217;s error and end-of-file indicators. */
KD_API void KD_APIENTRY kdClearerr(KDFile *file);

/* kdFseek: Reposition the file position indicator in a file. */
typedef enum {
    KD_SEEK_SET =  0, 
    KD_SEEK_CUR =  1, 
    KD_SEEK_END =  2
} KDfileSeekOrigin;
KD_API KDint KD_APIENTRY kdFseek(KDFile *file, KDoff offset, KDfileSeekOrigin origin);

/* kdFtell: Get the file position of an open file. */
KD_API KDoff KD_APIENTRY kdFtell(KDFile *file);

/* kdMkdir: Create new directory. */
KD_API KDint KD_APIENTRY kdMkdir(const KDchar *pathname);

/* kdRmdir: Delete a directory. */
KD_API KDint KD_APIENTRY kdRmdir(const KDchar *pathname);

/* kdRename: Rename a file. */
KD_API KDint KD_APIENTRY kdRename(const KDchar *src, const KDchar *dest);

/* kdRemove: Delete a file. */
KD_API KDint KD_APIENTRY kdRemove(const KDchar *pathname);

/* kdTruncate: Truncate or extend a file. */
KD_API KDint KD_APIENTRY kdTruncate(const KDchar *pathname, KDoff length);

/* kdStat, kdFstat: Return information about a file. */
typedef struct KDStat {
    KDmode st_mode;
    KDoff st_size;
    KDtime st_mtime;
} KDStat;
KD_API KDint KD_APIENTRY kdStat(const KDchar *pathname, struct KDStat *buf);
KD_API KDint KD_APIENTRY kdFstat(const KDFile *file, struct KDStat *buf);
#define KD_ISREG(m) ???
#define KD_ISDIR(m) ???
#define KD_READABLE(m) ???
#define KD_WRITABLE(m) ???

/* kdOpenDir: Open a directory ready for listing. */
typedef struct KDDir KDDir;
KD_API KDDir *KD_APIENTRY kdOpenDir(const KDchar *pathname);

/* kdReadDir: Return the next file in a directory. */
typedef struct KDDirent {
    KDchar d_name[256];
} KDDirent;
KD_API KDDirent *KD_APIENTRY kdReadDir(KDDir *dir);

/* kdCloseDir: Close a directory. */
KD_API KDint KD_APIENTRY kdCloseDir(KDDir *dir);

/* kdGetFree: Get free space on a drive. */
KD_API KDoff KD_APIENTRY kdGetFree(const KDchar *pathname);

/* kdChdir: Change the current directory. */
KD_API KDint KD_APIENTRY kdChdir(const KDchar *pathname);

/* kdGetCwd: Get the current directory. */
KD_API KDchar *KD_APIENTRY kdGetCwd(KDchar *buf, KDsize buflen);

/*******************************************************
 * Network sockets
 *******************************************************/

/* KDSockaddr, KDSockaddr_in: Struct types for socket addresses. */
typedef struct KDSockaddr {
    KDint16 sa_family;
    KDuint8 sa_data[14];
} KDSockaddr;
#define KD_AF_INET 2
typedef struct KDSockaddr_in {
    KDint16 sin_family;
    KDuint32 sin_address;
    KDuint16 sin_port;
} KDSockaddr_in;

/* kdNameLookup: Look up a hostname. */
KD_API KDint KD_APIENTRY kdNameLookup(KDint type, const KDchar *hostname, void *eventuserptr);

/* kdNameLookupCancel: Selectively cancels ongoing kdNameLookup operations. */
KD_API void KD_APIENTRY kdNameLookupCancel(void *eventuserptr);

/* kdSocketCreate: Creates a socket. */
typedef struct KDSocket KDSocket;
KD_API KDSocket *KD_APIENTRY kdSocketCreate(KDint type, void *eventuserptr);
#define KD_SOCK_TCP 0
#define KD_SOCK_UDP 1

/* kdSocketClose: Closes a socket. */
KD_API KDint KD_APIENTRY kdSocketClose(KDSocket *socket);

/* kdSocketBind: Bind a socket. */
KD_API KDint KD_APIENTRY kdSocketBind(KDSocket *socket, const struct KDSockaddr *addr, KDsocklen addrlen, KDboolean reuse);
#define KD_INADDR_ANY 0

/* kdSocketGetName: Get the local address of a socket. */
KD_API KDint KD_APIENTRY kdSocketGetName(KDSocket *socket, struct KDSockaddr *addr, KDsocklen *addrlen);

/* kdSocketConnect: Connects a socket. */
KD_API KDint KD_APIENTRY kdSocketConnect(KDSocket *socket, const KDSockaddr *addr, KDsocklen addrlen);

/* kdSocketListen: Listen on a socket. */
KD_API KDint KD_APIENTRY kdSocketListen(KDSocket *socket, KDint backlog);

/* kdSocketAccept: Accept an incoming connection. */
KD_API KDSocket *KD_APIENTRY kdSocketAccept(KDSocket *socket, KDSockaddr *addr, KDsocklen *addrlen, void *eventuserptr);

/* kdSocketSend, kdSocketSendTo: Send data to a socket. */
KD_API KDint KD_APIENTRY kdSocketSend(KDSocket *socket, const void *buf, KDint len);
KD_API KDint KD_APIENTRY kdSocketSendTo(KDSocket *socket, const void *buf, KDint len, const KDSockaddr *addr, KDsocklen addrlen);

/* kdSocketRecv, kdSocketRecvFrom: Receive data from a socket. */
KD_API KDint KD_APIENTRY kdSocketRecv(KDSocket *socket, void *buf, KDint len);
KD_API KDint KD_APIENTRY kdSocketRecvFrom(KDSocket *socket, void *buf, KDint len, KDSockaddr *addr, KDsocklen *addrlen);

/* kdHtonl: Convert a 32-bit integer from host to network byte order. */
KD_API KDuint32 KD_APIENTRY kdHtonl(KDuint32 hostlong);

/* kdHtons: Convert a 16-bit integer from host to network byte order. */
KD_API KDuint16 KD_APIENTRY kdHtons(KDuint16 hostshort);

/* kdNtohl: Convert a 32-bit integer from network to host byte order. */
KD_API KDuint32 KD_APIENTRY kdNtohl(KDuint32 netlong);

/* kdNtohs: Convert a 16-bit integer from network to host byte order. */
KD_API KDuint16 KD_APIENTRY kdNtohs(KDuint16 netshort);

/* kdInetAton: Convert a &#8220;dotted quad&#8221; format address to an integer. */
KD_API KDint KD_APIENTRY kdInetAton(const KDchar *cp, KDuint32 *inp);

/* kdInetNtoa: Convert an address as a 32-bit integer to dotted quad format */
KD_API const KDchar *KD_APIENTRY kdInetNtoa(KDuint32 in);

/* KD_EVENT_SOCKET_READABLE: Event to indicate that a socket is readable. */
#define KD_EVENT_SOCKET_READABLE 0x100
typedef struct KDEventSocketReadable {
    KDSocket *socket;
} KDEventSocketReadable;

/* KD_EVENT_SOCKET_WRITABLE: Event to indicate that a socket is writable. */
#define KD_EVENT_SOCKET_WRITABLE 0x101
typedef struct KDEventSocketWritable {
    KDSocket *socket;
} KDEventSocketWritable;

/* KD_EVENT_SOCKET_ERROR: Event to indicate that a socket has an error. */
#define KD_EVENT_SOCKET_ERROR 0x105
typedef struct KDEventSocketError {
    KDSocket *socket;
} KDEventSocketError;

/* KD_EVENT_SOCKET_CONNECT_COMPLETE: Event generated when a socket connect is complete */
#define KD_EVENT_SOCKET_CONNECT_COMPLETE 0x102
typedef struct KDEventSocketConnect {
    KDSocket *socket;
    KDint32 error;
} KDEventSocketConnect;

/* KD_EVENT_SOCKET_INCOMING: Event generated when a listening socket detects an incoming connection or an error. */
#define KD_EVENT_SOCKET_INCOMING 0x103
typedef struct KDEventSocketIncoming {
    KDSocket *socket;
} KDEventSocketIncoming;

/* KD_EVENT_NAME_LOOKUP_COMPLETE: kdNameLookup complete event. */
#define KD_EVENT_NAME_LOOKUP_COMPLETE 0x104
typedef struct KDEventNameLookup {
    KDint32 error;
    KDint32 resultlen;
    const KDSockaddr *result;
    KDboolean more;
} KDEventNameLookup;
#define KD_HOST_NOT_FOUND 1
#define KD_NO_DATA 4
#define KD_NO_RECOVERY 3
#define KD_TRY_AGAIN 2

/*******************************************************
 * Input/output
 *******************************************************/

/* KD_EVENT_INPUT: Input changed event. */
#define KD_EVENT_INPUT 0x200
        
typedef struct KDEventInput {
    KDint32 index;
    union {
        KDint32 i;
        KDint64 l;
        KDfloat32 f;
    } value;
} KDEventInput;

/* KD_EVENT_INPUT_POINTER: Pointer input changed event. */
#define KD_EVENT_INPUT_POINTER 0x201
typedef struct KDEventInputPointer {
    KDint32 index;
    KDint32 select;
    KDint32 x;
    KDint32 y;
} KDEventInputPointer;

/* KD_EVENT_INPUT_STICK: Joystick stick changed event. */
#define KD_EVENT_INPUT_STICK 0x202
typedef struct KDEventInputStick {
    KDint32 index;
    KDint32 x;
    KDint32 y;
    KDint32 z;
} KDEventInputStick;

/* kdInputEventEnable: Enable events for inputs in an I/O group. */
KD_API KDint KD_APIENTRY kdInputEventEnable(KDint idx, KDint enable);

/* kdInputPollb, kdInputPolli, kdInputPolll, kdInputPollf: poll inputs */
KD_API KDint KD_APIENTRY kdInputPollb(KDint startidx, KDuint numidxs, KDint32 *buffer);
KD_API KDint KD_APIENTRY kdInputPolli(KDint startidx, KDuint numidxs, KDint32 *buffer);
KD_API KDint KD_APIENTRY kdInputPolll(KDint startidx, KDuint numidxs, KDint64 *buffer);
KD_API KDint KD_APIENTRY kdInputPollf(KDint startidx, KDuint numidxs, KDfloat32 *buffer);

/* kdOutputSeti, kdOutputSetf: set outputs */
KD_API KDint KD_APIENTRY kdOutputSeti(KDint startidx, KDuint numidxs, const KDint32 *buffer);
KD_API KDint KD_APIENTRY kdOutputSetf(KDint startidx, KDuint numidxs, const KDfloat32 *buffer);

/* KD_IOGROUP_GAMEKEYS: I/O group for game keys. */
#define KD_IOGROUP_GAMEKEYS 0x1000
#define KD_IO_GAMEKEYS_AVAILABILITY    (KD_IOGROUP_GAMEKEYS + 0)
#define KD_IO_GAMEKEYS_UP              (KD_IOGROUP_GAMEKEYS + 1)
#define KD_IO_GAMEKEYS_LEFT            (KD_IOGROUP_GAMEKEYS + 2)
#define KD_IO_GAMEKEYS_RIGHT           (KD_IOGROUP_GAMEKEYS + 3)
#define KD_IO_GAMEKEYS_DOWN            (KD_IOGROUP_GAMEKEYS + 4)
#define KD_IO_GAMEKEYS_FIRE            (KD_IOGROUP_GAMEKEYS + 5)
#define KD_IO_GAMEKEYS_A               (KD_IOGROUP_GAMEKEYS + 6)
#define KD_IO_GAMEKEYS_B               (KD_IOGROUP_GAMEKEYS + 7)
#define KD_IO_GAMEKEYS_C               (KD_IOGROUP_GAMEKEYS + 8)
#define KD_IO_GAMEKEYS_D               (KD_IOGROUP_GAMEKEYS + 9)

/* KD_IOGROUP_GAMEKEYSNC: I/O group for game keys, no chording. */
#define KD_IOGROUP_GAMEKEYSNC 0x1100
#define KD_IO_GAMEKEYSNC_AVAILABILITY  (KD_IOGROUP_GAMEKEYSNC + 0)
#define KD_IO_GAMEKEYSNC_UP            (KD_IOGROUP_GAMEKEYSNC + 1)
#define KD_IO_GAMEKEYSNC_LEFT          (KD_IOGROUP_GAMEKEYSNC + 2)
#define KD_IO_GAMEKEYSNC_RIGHT         (KD_IOGROUP_GAMEKEYSNC + 3)
#define KD_IO_GAMEKEYSNC_DOWN          (KD_IOGROUP_GAMEKEYSNC + 4)
#define KD_IO_GAMEKEYSNC_FIRE          (KD_IOGROUP_GAMEKEYSNC + 5)
#define KD_IO_GAMEKEYSNC_A             (KD_IOGROUP_GAMEKEYSNC + 6)
#define KD_IO_GAMEKEYSNC_B             (KD_IOGROUP_GAMEKEYSNC + 7)
#define KD_IO_GAMEKEYSNC_C             (KD_IOGROUP_GAMEKEYSNC + 8)
#define KD_IO_GAMEKEYSNC_D             (KD_IOGROUP_GAMEKEYSNC + 9)

/* KD_IOGROUP_PHONEKEYPAD: I/O group for phone keypad. */
#define KD_IOGROUP_PHONEKEYPAD 0x2000
#define KD_IO_PHONEKEYPAD_AVAILABILITY  (KD_IOGROUP_PHONEKEYPAD + 0)
#define KD_IO_PHONEKEYPAD_0             (KD_IOGROUP_PHONEKEYPAD + 1)
#define KD_IO_PHONEKEYPAD_1             (KD_IOGROUP_PHONEKEYPAD + 2)
#define KD_IO_PHONEKEYPAD_2             (KD_IOGROUP_PHONEKEYPAD + 3)
#define KD_IO_PHONEKEYPAD_3             (KD_IOGROUP_PHONEKEYPAD + 4)
#define KD_IO_PHONEKEYPAD_4             (KD_IOGROUP_PHONEKEYPAD + 5)
#define KD_IO_PHONEKEYPAD_5             (KD_IOGROUP_PHONEKEYPAD + 6)
#define KD_IO_PHONEKEYPAD_6             (KD_IOGROUP_PHONEKEYPAD + 7)
#define KD_IO_PHONEKEYPAD_7             (KD_IOGROUP_PHONEKEYPAD + 8)
#define KD_IO_PHONEKEYPAD_8             (KD_IOGROUP_PHONEKEYPAD + 9)
#define KD_IO_PHONEKEYPAD_9             (KD_IOGROUP_PHONEKEYPAD + 10)
#define KD_IO_PHONEKEYPAD_STAR          (KD_IOGROUP_PHONEKEYPAD + 11)
#define KD_IO_PHONEKEYPAD_HASH          (KD_IOGROUP_PHONEKEYPAD + 12)
#define KD_IO_PHONEKEYPAD_LEFTSOFT      (KD_IOGROUP_PHONEKEYPAD + 13)
#define KD_IO_PHONEKEYPAD_RIGHTSOFT     (KD_IOGROUP_PHONEKEYPAD + 14)

/* KD_IOGROUP_VIBRATE: I/O group for vibrate. */
#define KD_IOGROUP_VIBRATE 0x3000
#define KD_IO_VIBRATE_AVAILABILITY  (KD_IOGROUP_VIBRATE + 0)
#define KD_IO_VIBRATE_MINFREQUENCY  (KD_IOGROUP_VIBRATE + 1)
#define KD_IO_VIBRATE_MAXFREQUENCY  (KD_IOGROUP_VIBRATE + 2)
#define KD_IO_VIBRATE_VOLUME        (KD_IOGROUP_VIBRATE + 3)
#define KD_IO_VIBRATE_FREQUENCY     (KD_IOGROUP_VIBRATE + 4)

/* KD_IOGROUP_POINTER: I/O group for pointer. */
#define KD_IOGROUP_POINTER 0x4000
#define KD_IO_POINTER_X             (KD_IOGROUP_POINTER + 0)
#define KD_IO_POINTER_Y             (KD_IOGROUP_POINTER + 1)
#define KD_IO_POINTER_SELECT        (KD_IOGROUP_POINTER + 2)

/* KD_IOGROUP_BACKLIGHT: I/O group for backlight. */
#define KD_IOGROUP_BACKLIGHT 0x5000
#define KD_IO_BACKLIGHT_FORCE (KD_IOGROUP_BACKLIGHT + 0)

/* KD_IOGROUP_JOGDIAL: I/O group for a jog dial. */
#define KD_IOGROUP_JOGDIAL 0x6000
#define KD_IO_JOGDIAL_AVAILABILITY  (KD_IOGROUP_JOGDIAL + 0)
#define KD_IO_JOGDIAL_UP            (KD_IOGROUP_JOGDIAL + 1)
#define KD_IO_JOGDIAL_LEFT          (KD_IOGROUP_JOGDIAL + 2)
#define KD_IO_JOGDIAL_RIGHT         (KD_IOGROUP_JOGDIAL + 3)
#define KD_IO_JOGDIAL_DOWN          (KD_IOGROUP_JOGDIAL + 4)
#define KD_IO_JOGDIAL_SELECT        (KD_IOGROUP_JOGDIAL + 5)

/* KD_IOGROUP_JOYSTICK: I/O group for joystick. */
#define KD_IOGROUP_JOYSTICK 0x10000
#define KD_IO_JOYSTICK_NUMSTICKS    (KD_IOGROUP_JOYSTICK + 0)
#define KD_IO_JOYSTICK_NUMBUTTONS   (KD_IOGROUP_JOYSTICK + 1)
#define KD_IO_JOYSTICK_NUMHATS      (KD_IOGROUP_JOYSTICK + 2)
#define KD_IO_JOYSTICK_NUMBALLS     (KD_IOGROUP_JOYSTICK + 3)

#define KD_IO_JOYSTICK_STICK            (KD_IOGROUP_JOYSTICK + 4)
#define KD_IO_JOYSTICK_STICK_NUMAXES    (KD_IO_JOYSTICK_STICK + 0)
#define KD_IO_JOYSTICK_X                (KD_IO_JOYSTICK_STICK + 1)
#define KD_IO_JOYSTICK_Y                (KD_IO_JOYSTICK_STICK + 2)
#define KD_IO_JOYSTICK_Z                (KD_IO_JOYSTICK_STICK + 3)
#define KD_IO_JOYSTICK_HAT              (KD_IOGROUP_JOYSTICK + 8)
#define KD_IO_JOYSTICK_HAT_UP           (KD_IO_JOYSTICK_HAT + 0)
#define KD_IO_JOYSTICK_HAT_LEFT         (KD_IO_JOYSTICK_HAT + 1)
#define KD_IO_JOYSTICK_HAT_RIGHT        (KD_IO_JOYSTICK_HAT + 2)
#define KD_IO_JOYSTICK_HAT_DOWN         (KD_IO_JOYSTICK_HAT + 3)
#define KD_IO_JOYSTICK_BALL             (KD_IOGROUP_JOYSTICK + 12)
#define KD_IO_JOYSTICK_BALL_X           (KD_IO_JOYSTICK_BALL + 0)
#define KD_IO_JOYSTICK_BALL_Y           (KD_IO_JOYSTICK_BALL + 1)
#define KD_IO_JOYSTICK_BUTTON           (KD_IOGROUP_JOYSTICK + 32)
#define KD_IO_JOYSTICK_STRIDE 64

/* KD_IO_UNDEFINED: I/O items reserved for implementation-dependent use. */
#define KD_IO_UNDEFINED 0x40000000

/*******************************************************
 * Windowing
 *******************************************************/
#ifdef KD_WINDOW_SUPPORTED
#include <EGL/egl.h>
typedef struct KDWindow KDWindow;

/* kdCreateFullScreenWindow: Create a full-screen window. */
KD_API KDWindow *KD_APIENTRY kdCreateFullScreenWindow(EGLDisplay display, const void *mode, void *eventuserptr);

/* kdCreateWindow: Create a window. */
KD_API KDWindow *KD_APIENTRY kdCreateWindow(EGLDisplay display, void *eventuserptr);

/* kdDestroyWindow: Destroy a window. */
KD_API void KD_APIENTRY kdDestroyWindow(KDWindow *window);

/* kdShowWindow: Set window&#8217;s visibility status. */
KD_API KDint KD_APIENTRY kdShowWindow(KDWindow *window, KDint status);
#define KD_WINDOWSTATUS_HIDDEN 0
#define KD_WINDOWSTATUS_VISIBLE 1
#define KD_WINDOWSTATUS_MINIMIZED 2

/* kdGetWindowNativeType: Get the window handle for passing to EGL */
KD_API void *KD_APIENTRY kdGetWindowNativeType(KDWindow *window);

/* kdActivateWindow: Give focus to a window */
KD_API KDint KD_APIENTRY kdActivateWindow(KDWindow *window);

/* kdSetWindowCaption: Set window caption */
KD_API KDint KD_APIENTRY kdSetWindowCaption(KDWindow *window, const KDchar *caption);

/* kdGetWindowPosition: Get window position */
KD_API KDint KD_APIENTRY kdGetWindowPosition(KDWindow *window, KDint *x, KDint *y);

/* kdSetWindowPosition: Set window position */
KD_API KDint KD_APIENTRY kdSetWindowPosition(KDWindow *window, KDint x, KDint y);

/* kdSetWindowSize: Set window size */
KD_API KDint KD_APIENTRY kdSetWindowSize(KDWindow *window, KDint width, KDint height);

/* KD_EVENT_WINDOW_CLOSE: Event to request to close window. */
#define KD_EVENT_WINDOW_CLOSE 2

/* KD_EVENT_WINDOW_RESIZE: Window resize event. */
#define KD_EVENT_WINDOW_RESIZE 5

/* KD_EVENT_WINDOW_FOCUS: Window focus gained/lost event. */
#define KD_EVENT_WINDOW_FOCUS 6
typedef struct KDEventWindowFocus {
    KDint hasfocus;
} KDEventWindowFocus;
#endif /* KD_WINDOW_SUPPORTED */

/*******************************************************
 * Assertions and logging
 *******************************************************/

/* kdAssert: Test assertion and call assertion handler if it is false */
#ifdef KD_NDEBUG
#define kdAssert(c)
#else
#define kdAssert(c) ((c) || (kdHandleAssertion(#c, __FILE__, __LINE__), 0))
#endif

/* kdHandleAssertion: Handle assertion failure. */
KD_API void KD_APIENTRY kdHandleAssertion(const KDchar *condition, const KDchar *filename, KDint linenumber);

/* kdLogMessage: Output a log message. */
#ifdef KD_NDEBUG
#define kdLogMessage(s)
#else
KD_API void KD_APIENTRY kdLogMessage(const KDchar *string);
#endif

/* struct KDEvent delayed to the end as it uses event data structs from
 * other parts of the .h file. */
struct KDEvent {
    KDust timestamp;
    KDint32 type;
    void *userptr;
    union KDEventData {
        KDEventInput input;
        KDEventInputPointer inputpointer;
        KDEventInputStick inputstick;
        KDEventSocketReadable socketreadable;
        KDEventSocketWritable socketwritable;
        KDEventSocketError socketerror;
        KDEventSocketConnect socketconnect;
        KDEventSocketIncoming socketincoming;
        KDEventNameLookup namelookup;
        KDEventWindowFocus windowfocus;
        KDEventUser user;
    } data;
};

#ifdef __cplusplus
}
#endif

#endif /* __kd_h_ */

