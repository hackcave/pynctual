/*

Copyright (c) 2003-2015 Futronic Technology Company Ltd. All rights reserved.

Abstract:

Definitions and prototypes for the Futronic Scanner API.

*/

#ifndef __FUTRONIC_SCAN_API_H__
#define __FUTRONIC_SCAN_API_H__

#if ( !defined( __WIN32__ ) && ( defined( WIN32 ) || defined( _WIN32 ) || defined( _WIN32_WCE ) ) )
#  define __WIN32__
#  include <windows.h>
#endif

#if defined( MSDOS ) || defined( __MSDOS__ ) || defined( __OS2__ ) || defined( _WINDOWS ) || defined ( _Windows ) || defined( __WIN32__ )
#  define FTR_OS_DOS_WIN_OS2
#elif defined( unix ) || defined( __unix__ ) || defined( __sun ) || defined( __APPLE__ )
#  define FTR_OS_UNIX
#elif defined( VAX )
#  define FTR_OS_VAX
#else
#  error Cannot determine target OS - contact your vendor for support
#endif

#if defined( __sun )
#  include <sys/isa_defs.h>
#endif

#if defined( __WIN32__ )
#  define FTR_PACKED
#elif defined( FTR_OS_UNIX )
#  define FTR_PACKED __attribute__ ((aligned(1),packed))
#else
#  error Cannot determine alligment - contact your vendor for support
#endif

#ifndef TRUE
#  define TRUE 1
#endif

#ifndef FALSE
#  define FALSE 0
#endif

#ifndef NULL
#  define NULL 0
#endif

#if defined( __UNIX__ ) || defined( unix ) || defined( __APPLE__ )
#include <sys/time.h>
#include <sys/param.h>
#include <stdlib.h>

#ifdef USE_STD_MINMAX
#include <algorithm>
#else

#ifndef min
#define min(a, b)  (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#endif

#endif

#ifndef ERROR_NOT_ENOUGH_MEMORY
#define ERROR_NOT_ENOUGH_MEMORY 8
#endif

#ifndef ERROR_WRITE_PROTECT
#define ERROR_WRITE_PROTECT 19
#endif

#ifndef ERROR_NOT_READY
#define ERROR_NOT_READY 21
#endif

#ifndef ERROR_NOT_SUPPORTED
#define ERROR_NOT_SUPPORTED 50
#endif

#ifndef ERROR_INVALID_PARAMETER
#define ERROR_INVALID_PARAMETER 87
#endif

#ifndef ERROR_CALL_NOT_IMPLEMENTED
#define ERROR_CALL_NOT_IMPLEMENTED 120
#endif

#ifndef ERROR_NO_MORE_ITEMS
#define ERROR_NO_MORE_ITEMS 259
#endif

#ifndef ERROR_PORT_UNREACHABLE
#define ERROR_PORT_UNREACHABLE 1234
#endif

#ifndef ERROR_NO_SYSTEM_RESOURCES
#define ERROR_NO_SYSTEM_RESOURCES 1450
#endif

#ifndef ERROR_TIMEOUT
#define ERROR_TIMEOUT 1460
#endif

#ifndef ERROR_BAD_CONFIGURATION
#define ERROR_BAD_CONFIGURATION 1610
#endif

#ifndef ERROR_MESSAGE_EXCEEDS_MAX_SIZE
#define ERROR_MESSAGE_EXCEEDS_MAX_SIZE 4336
#endif

#ifndef ERROR_ALREADY_EXISTS
#define ERROR_ALREADY_EXISTS 183
#endif

#ifndef ERROR_MORE_DATA
#define ERROR_MORE_DATA 234L
#endif

#if defined( __WIN32__ )
#  define FTR_API_PREFIX
#  define       __stdcall
#elif defined( FTR_OS_UNIX ) || defined( FTR_OS_VAX )
#  define FTR_API_PREFIX
#   define FTR_API
#elif defined( __OS2__ )
#  define FTR_API_PREFIX
#  define       _pascal _export
#else
#  define FTR_API_PREFIX
#  define       _far _pascal
#endif
#define FTR_CALLBACK    FTR_API

typedef signed char         FTR_INT8;
typedef signed short        FTR_INT16;
typedef signed int          FTR_INT32;
typedef signed long long    FTR_INT64;

typedef unsigned char       FTR_UINT8;
typedef unsigned short      FTR_UINT16;
typedef unsigned int        FTR_UINT32;
typedef unsigned long long  FTR_UINT64;

typedef void *              void *;
typedef int                 int;
#if defined( __WIN32__ )
typedef BYTE                FTR_BYTE;
typedef WORD                FTR_WORD;
typedef DWORD               FTR_DWORD;
#else
typedef FTR_UINT8           FTR_BYTE;
typedef FTR_UINT16          FTR_WORD;
typedef FTR_UINT32          FTR_DWORD;
#endif

typedef void *              FTR_PVOID;
typedef const void *        FTR_PCVOID;
typedef int *          FTR_PBOOL;
typedef FTR_BYTE *          FTR_PBYTE;
typedef FTR_WORD *          FTR_PWORD;
typedef FTR_DWORD *         FTR_PDWORD;

typedef void *              FTR_CERTCONTEXT;

#define FTR_CERT_INVALID_CONTEXT                        ((void *)0)

/*
 * Supported certificate encodign types
 */
#define FTR_CERT_ENCODING_V1_BINARY                     1

/*
 * Supported certificate parameters
 */
#define FTR_CERT_SUBJECT_NAME                           1
#define FTR_CERT_ISSUER_NAME                            2
#define FTR_CERT_PUBLIC_KEY_ID                          3
#define FTR_CERT_PUBLIC_KEY_DATA                        4
#define FTR_CERT_ISSUER_KEY_ID                          5
#define FTR_CERT_ENCODED_KEY_BLOB                       6
#define FTR_CERT_SIGNATURE                              7

/*
* Supported algoritm identifiers
*/
#define FTR_CERT_ALGID_DH_1024_SHA512                   0x1101
#define FTR_CERT_ALGID_DH_2048_SHA512                   0x1102
#define FTR_CERT_ALGID_DH_3072_SHA512                   0x1103
#define FTR_CERT_ALGID_DH_4096_SHA512                   0x1104

#define FTR_CERT_ALGID_ECDSA_192_SHA512                 0x2101
#define FTR_CERT_ALGID_ECDSA_224_SHA512                 0x2102
#define FTR_CERT_ALGID_ECDSA_256_SHA512                 0x2103
#define FTR_CERT_ALGID_ECDSA_384_SHA512                 0x2104
#define FTR_CERT_ALGID_ECDSA_521_SHA512                 0x2105

/*
 * Supported store flags
 */
#define FTR_STORE_FLAGS_ADD_REPLACE_EXISTING            0x00000001
#define FTR_STORE_FLAGS_ADD_SELF_SIGNED                 0x00000002

/*
 * Supported store find parameters
 */
#define FTR_STORE_FIND_CERT_ISSUER_NAME                 1
#define FTR_STORE_FIND_CERT_SUBJECT_NAME                2

/*
* Verify result
*/
#define FTR_CERT_VERIFY_RES_OK                          0
#define FTR_CERT_VERIFY_RES_SIGNATURE_INVALID           1
#define FTR_CERT_VERIFY_RES_ALGORITHM_INVALID           2
#define FTR_CERT_VERIFY_RES_SIGNATURE_VERIFY_FAILED     3
#define FTR_CERT_VERIFY_RES_NO_MEMORY                   4
#define FTR_CERT_VERIFY_RES_FAILED                      5


#if defined( __cplusplus )
extern "C" { /* assume C declarations for C++ */
#endif


#if defined(__WIN32__)
#pragma pack(push, 1)
#endif

#define FTR_MAX_INTERFACE_NUMBER                        128

#define FTR_OPTIONS_CHECK_FAKE_REPLICA                  0x00000001
#define FTR_OPTIONS_DETECT_FAKE_FINGER                  FTR_OPTIONS_CHECK_FAKE_REPLICA
#define FTR_OPTIONS_FAST_FINGER_DETECT_METHOD           0x00000002
#define FTR_OPTIONS_RECEIVE_LONG_IMAGE                  0x00000004
#define FTR_OPTIONS_RECEIVE_FAKE_IMAGE                  0x00000008
#define FTR_OPTIONS_SCALE_IMAGE                         0x00000010
#define FTR_OPTIONS_IMPROVE_IMAGE                       0x00000020 /* for PIV compatible devices */
#define FTR_OPTIONS_INVERT_IMAGE                        0x00000040
#define FTR_OPTIONS_PREVIEW_MODE                        0x00000080
#define FTR_OPTIONS_IMAGE_FORMAT_MASK                   0x00000700
#define FTR_OPTIONS_IMAGE_FORMAT_1                      0x00000100
#define FTR_OPTIONS_ELIMINATE_BACKGROUND                0x00000800
#define FTR_OPTIONS_IMPROVE_BACKGROUND                  0x00001000
#define FTR_OPTIONS_ROLL_THRESHOLD_MASK                 0x001F0000
#define FTR_OPTIONS_ROLL_THRESHOLD_1                    0x00010000
#define FTR_OPTIONS_DISABLE_MOVABLE_FINGER_CHECKING     0x00200000

#define FTR_GLOBAL_ENABLE_REMOTE_SESSION_DETECTION      0x00000001
#define FTR_GLOBAL_SYNC_DIR                             0x00000002 /* for Android only */
#define FTR_GLOBAL_USB_HOST_CONTEXT_VERSION             0x00000003 /* for Android only */
#define FTR_GLOBAL_SAVE_SESSION_TO_FILE                 0x00000004
#define FTR_GLOBAL_BLOCK_UNIX_SIGNALS                   0x00000005 /* for Unix/Android only */
#define FTR_GLOBAL_DISABLE_ENCRYPTION                   0x00000006
#define FTR_GLOBAL_METROUSBAPI_CONTEXT_VERSION          0x00000007
#define FTR_GLOBAL_CITRIX_USE_VIRTUAL_CHANNEL           0x00000008

#define FTR_GLOBAL_VALUE_REMOTE_SESSION_ENABLE          0x00000001
#define FTR_GLOBAL_VALUE_REMOTE_SESSION_DISABLE         0x00000000

#define FTR_GLOBAL_VALUE_USB_HOST_CONTEXT_VERSION_MAX   0x00000002

#define FTR_LIGHT_NO_LIGHT                              0x00 /* Can not be combined with other flags */
#define FTR_LIGHT_TURN_ON( x )                          (0x80 | (x))
#define FTR_LIGHT_TURN_OFF( x )                         (0x7F & (x))
#define FTR_LIGHT_MAIN_IFRED                            0x01
#define FTR_LIGHT_ADDITIONAL_IFRED                      0x02
#define FTR_LIGHT_BACK_IFRED                            0x04
#define FTR_LIGHT_GREEN                                 0x08
#define FTR_LIGHT_OFF_MAIN_IFRED                        FTR_LIGHT_TURN_OFF( FTR_LIGHT_MAIN_IFRED )
#define FTR_LIGHT_OFF_ADDITIONAL_IFRED                  FTR_LIGHT_TURN_OFF( FTR_LIGHT_ADDITIONAL_IFRED )
#define FTR_LIGHT_OFF_BACK_IFRED                        FTR_LIGHT_TURN_OFF( FTR_LIGHT_BACK_IFRED )
#define FTR_LIGHT_OFF_GREEN                             FTR_LIGHT_TURN_OFF( FTR_LIGHT_GREEN )
#define FTR_LIGHT_ON_MAIN_IFRED                         FTR_LIGHT_TURN_ON( FTR_LIGHT_MAIN_IFRED )
#define FTR_LIGHT_ON_ADDITIONAL_IFRED                   FTR_LIGHT_TURN_ON( FTR_LIGHT_ADDITIONAL_IFRED )
#define FTR_LIGHT_ON_BACK_IFRED                         FTR_LIGHT_TURN_ON( FTR_LIGHT_BACK_IFRED )
#define FTR_LIGHT_ON_GREEN                              FTR_LIGHT_TURN_ON( FTR_LIGHT_GREEN )

#define FTR_ERROR_BASE                                  0x20000000
#define FTR_ERROR_CODE( x )                             (FTR_ERROR_BASE | (x))

#define FTR_ERROR_NO_ERROR                              0
#define FTR_ERROR_EMPTY_FRAME                           4306 /* ERROR_EMPTY */
#define FTR_ERROR_MOVABLE_FINGER                        FTR_ERROR_CODE( 0x0001 )
#define FTR_ERROR_NO_FRAME                              FTR_ERROR_CODE( 0x0002 )
#define FTR_ERROR_USER_CANCELED                         FTR_ERROR_CODE( 0x0003 )
#define FTR_ERROR_HARDWARE_INCOMPATIBLE                 FTR_ERROR_CODE( 0x0004 )
#define FTR_ERROR_FIRMWARE_INCOMPATIBLE                 FTR_ERROR_CODE( 0x0005 )
#define FTR_ERROR_INVALID_AUTHORIZATION_CODE            FTR_ERROR_CODE( 0x0006 )
#define FTR_ERROR_ROLL_NOT_STARTED                      FTR_ERROR_CODE( 0x0007 )
#define FTR_ERROR_ROLL_PROGRESS_DATA                    FTR_ERROR_CODE( 0x0008 )
#define FTR_ERROR_ROLL_TIMEOUT                          FTR_ERROR_CODE( 0x0009 )
#define FTR_ERROR_ROLL_ABORTED                          FTR_ERROR_CODE( 0x000A )
#define FTR_ERROR_ROLL_ALREADY_STARTED                  FTR_ERROR_CODE( 0x000B )
#define FTR_ERROR_ROLL_PROGRESS_REMOVE_FINGER           FTR_ERROR_CODE( 0x000C )
#define FTR_ERROR_ROLL_PROGRESS_PUT_FINGER              FTR_ERROR_CODE( 0x000D )
#define FTR_ERROR_ROLL_PROGRESS_POST_PROCESSING         FTR_ERROR_CODE( 0x000E )
#define FTR_ERROR_FINGER_IS_PRESENT                     FTR_ERROR_CODE( 0x000F )
#define FTR_ERROR_NULL_PARAMETER                        FTR_ERROR_CODE( 0x0010 )
#define FTR_ERROR_LIBUSB_ERROR                          FTR_ERROR_CODE( 0x0011 )
#define FTR_ERROR_VERSION_NOT_SUPPORTED                 FTR_ERROR_CODE( 0x0012 )
#define FTR_ERROR_BAD_CALLBACK_FUNCTION                 FTR_ERROR_CODE( 0x0013 )
#define FTR_ERROR_GENERAL_ENCRYPTION                    FTR_ERROR_CODE( 0x0014 )
#define FTR_ERROR_BAD_DATA                              FTR_ERROR_CODE( 0x0015 )
#define FTR_ERROR_BAD_PUBLIC_KEY                        FTR_ERROR_CODE( 0x0016 )
#define FTR_ERROR_ADD_SELFSIGNED                        FTR_ERROR_CODE( 0x0017 )
#define FTR_ERROR_ISSUER_NOT_FOUND                      FTR_ERROR_CODE( 0x0018 )
#define FTR_ERROR_SIGNATURE_VERIFY_FAILED               FTR_ERROR_CODE( 0x0019 )
    /* Other return codes are Windows-compatible */
#define FTR_ERROR_NO_MORE_ITEMS                         ERROR_NO_MORE_ITEMS
#define FTR_ERROR_NOT_ENOUGH_MEMORY                     ERROR_NOT_ENOUGH_MEMORY
#define FTR_ERROR_NO_SYSTEM_RESOURCES                   ERROR_NO_SYSTEM_RESOURCES
#define FTR_ERROR_TIMEOUT                               ERROR_TIMEOUT
#define FTR_ERROR_NOT_READY                             ERROR_NOT_READY
#define FTR_ERROR_BAD_CONFIGURATION                     ERROR_BAD_CONFIGURATION
#define FTR_ERROR_INVALID_PARAMETER                     ERROR_INVALID_PARAMETER
#define FTR_ERROR_CALL_NOT_IMPLEMENTED                  ERROR_CALL_NOT_IMPLEMENTED
#define FTR_ERROR_NOT_SUPPORTED                         ERROR_NOT_SUPPORTED
#define FTR_ERROR_WRITE_PROTECT                         ERROR_WRITE_PROTECT
#define FTR_ERROR_MESSAGE_EXCEEDS_MAX_SIZE              ERROR_MESSAGE_EXCEEDS_MAX_SIZE
#define FTR_ERROR_PORT_UNREACHABLE                      ERROR_PORT_UNREACHABLE
#define FTR_ERROR_ALREADY_EXIST                         ERROR_ALREADY_EXISTS
#define FTR_ERROR_MORE_DATA                             ERROR_MORE_DATA

#define FTR_CONST_DIODE_OFF                             ((FTR_BYTE)0)
#define FTR_CONST_DIODE_ON                              ((FTR_BYTE)255)

#define FTR_LOG_MASK_OFF                                0
#define FTR_LOG_MASK_TO_FILE                            0x00000001
#define FTR_LOG_MASK_TO_AUX                             0x00000002
#define FTR_LOG_MASK_TIMESTAMP                          0x00000004
#define FTR_LOG_MASK_THREAD_ID                          0x00000008
#define FTR_LOG_MASK_PROCESS_ID                         0x00000010

#define FTR_LOG_LEVEL_MIN                               0
#define FTR_LOG_LEVEL_OPTIMAL                           1
#define FTR_LOG_LEVEL_FULL                              2

#define FTR_DEVICE_USB_1_1                              0
#define FTR_DEVICE_USB_2_0_TYPE_1                       1
#define FTR_DEVICE_SWEEP                                2
#define FTR_DEVICE_USB_2_0_TYPE_2                       4
#define FTR_DEVICE_USB_2_0_TYPE_3                       5
#define FTR_DEVICE_USB_2_0_TYPE_4                       6
#define FTR_DEVICE_USB_2_0_TYPE_50                      7
#define FTR_DEVICE_USB_2_0_TYPE_60                      8
#define FTR_DEVICE_USB_2_0_TYPE_25                      9
#define FTR_DEVICE_USB_2_0_TYPE_10                      10
#define FTR_DEVICE_USB_2_0_TYPE_80W                     11
#define FTR_DEVICE_USB_2_0_TYPE_90B                     12
#define FTR_DEVICE_USB_2_0_TYPE_80H                     13
#define FTR_DEVICE_USB_2_0_TYPE_88H                     14
#define FTR_DEVICE_USB_2_0_TYPE_64                      15
#define FTR_DEVICE_USB_2_0_TYPE_26E                     16
#define FTR_DEVICE_USB_2_0_TYPE_80HS                    17
#define FTR_DEVICE_USB_2_0_TYPE_26                      18
#define FTR_DEVICE_USB_2_0_TYPE_88HR                    19
#define FTR_DEVICE_USB_2_0_TYPE_98                      210

/*
byDeviceCompatibility:
        0 - USB 1.1 device,
        1 - USB 2.0 device (SOI966)
        2 - "Sweep" scanner
        3 - Reserved
        4 - USB 2.0 device (SOI968)
        5 - USB 2.0 device (FS88 compatible - SOI968)
        6 - USB 2.0 device (FS90 compatible - PAS202)
        7 - USB 2.0 device (FS50 compatible)
        8 - USB 2.0 device (FS60 compatible)
        9 - USB 2.0 device (FS25 compatible)
       10 - USB 2.0 device (FS10 compatible - JX-H22 )
       11 - USB 2.0 device (FS80 compatible - SOI968 + Prism w/o Lens)
       12 - USB 2.0 device (FS90 compatible - GC0303 w/o PIV)
       13 - USB 2.0 device (FS80H compatible - JX-H22 )
       14 - USB 2.0 device (FS88 compatible - JX-H22 )
       15 - USB 2.0 device (FS64 compatible)
       16 - USB 2.0 device (FS26E compatible)
       17 - USB 2.0 device (FS80H compatible - JX-H22+ Prism w/o Lens)
      210 - USB 2.0 device (FS98 compatible)
*/

typedef struct FTR_PACKED __FTRSCAN_DEVICE_INFO
{
    FTR_DWORD                           dwStructSize; /* [in, out] */
    FTR_BYTE                            byDeviceCompatibility;
    FTR_WORD                            wPixelSizeX;
    FTR_WORD                            wPixelSizeY;
} FTRSCAN_DEVICE_INFO, *PFTRSCAN_DEVICE_INFO;

typedef struct FTR_PACKED __FTRSCAN_IMAGE_SIZE
{
    int                                 nWidth;
    int                                 nHeight;
    int                                 nImageSize;
} FTRSCAN_IMAGE_SIZE, *PFTRSCAN_IMAGE_SIZE;

typedef struct FTR_PACKED __FTRSCAN_FAKE_REPLICA_PARAMETERS
{
    int                            bCalculated;
    int                                 nCalculatedSum1;
    int                                 nCalculatedSumFuzzy;
    int                                 nCalculatedSumEmpty;
    int                                 nCalculatedSum2;
    double                              dblCalculatedTremor;
    double                              dblCalculatedValue;
} FTRSCAN_FAKE_REPLICA_PARAMETERS, *PFTRSCAN_FAKE_REPLICA_PARAMETERS;

typedef struct FTR_PACKED __FTRSCAN_FAKE_REPLICA_BUFFER
{
    int                            bCalculated;
    int                                 nBuffers;
    int                                 nWidth;
    int                                 nHeight;
    int                                 nSize;
    FTR_PVOID                           pBuffers;
} FTRSCAN_FAKE_REPLICA_BUFFER, *PFTRSCAN_FAKE_REPLICA_BUFFER;

typedef struct FTR_PACKED __FTRSCAN_LFD_CONSTANTS
{
    int                                 nLMin;
    int                                 nLMax;
    int                                 nCMin;
    int                                 nCMax;
    int                                 nEEMin;
    int                                 nEEMax;
} FTRSCAN_LFD_CONSTANTS, *PFTRSCAN_LFD_CONSTANTS;

typedef struct FTR_PACKED __FTRSCAN_FRAME_PARAMETERS
{
    int                                 nContrastOnDose2;
    int                                 nContrastOnDose4;
    int                                 nDose;
    int                                 nBrightnessOnDose1;
    int                                 nBrightnessOnDose2;
    int                                 nBrightnessOnDose3;
    int                                 nBrightnessOnDose4;
    FTRSCAN_FAKE_REPLICA_PARAMETERS     FakeReplicaParams;
    FTR_BYTE                            Reserved[ 64 - sizeof( FTRSCAN_FAKE_REPLICA_PARAMETERS ) ];
} FTRSCAN_FRAME_PARAMETERS, *PFTRSCAN_FRAME_PARAMETERS;

typedef enum __FTRSCAN_INTERFACE_STATUS
{
    FTRSCAN_INTERFACE_STATUS_CONNECTED,
    FTRSCAN_INTERFACE_STATUS_DISCONNECTED
} FTRSCAN_INTERFACE_STATUS, *PFTRSCAN_INTERFACE_STATUS;

typedef struct FTR_PACKED __FTRSCAN_INTERFACES_LIST
{
    FTRSCAN_INTERFACE_STATUS            InterfaceStatus[ FTR_MAX_INTERFACE_NUMBER ];
} FTRSCAN_INTERFACES_LIST, *PFTRSCAN_INTERFACES_LIST;

#define FTR_VERSION_UNKNOWN_VERSION         0xFFFF

typedef struct FTR_PACKED __FTRSCAN_VERSION
{
    FTR_WORD                            wMajorVersionHi;
    FTR_WORD                            wMajorVersionLo;
    FTR_WORD                            wMinorVersionHi;
    FTR_WORD                            wMinorVersionLo;
} FTRSCAN_VERSION, *PFTRSCAN_VERSION;

typedef struct FTR_PACKED __FTRSCAN_VERSION_INFO
{
    FTR_DWORD                           dwVersionInfoSize; /* [in, out] */
    FTRSCAN_VERSION                     APIVersion;
    FTRSCAN_VERSION                     HardwareVersion;
    FTRSCAN_VERSION                     FirmwareVersion;
} FTRSCAN_VERSION_INFO, *PFTRSCAN_VERSION_INFO;

typedef struct FTR_PACKED __FTRSCAN_VAR_DOSE_EXTRA_PARAMS
{
    FTR_BYTE                            byNumberOfFramesMinusOne;
    FTR_BYTE                            byReserved1;
    FTR_BYTE                            byReserved2;
    FTR_BYTE                            byReserved3;
    FTR_BYTE                            byReserved4;
} FTRSCAN_VAR_DOSE_EXTRA_PARAMS, *PFTRSCAN_VAR_DOSE_EXTRA_PARAMS;

typedef struct FTR_PACKED __FTRPIPE_COMMAND_PACKET
{
    FTR_DWORD                           dwLabel;
    FTR_DWORD                           dwInDataSize;
    FTR_DWORD                           dwWaitDataSize;
    FTR_DWORD                           dwOperationStatus;
} FTRPIPE_COMMAND_PACKET, *PFTRPIPE_COMMAND_PACKET;

#define FTR_SCANNER_FEATURE_LFD                         1
#define FTR_SCANNER_FEATURE_DIODES                      2
#define FTR_SCANNER_FEATURE_GET_IMAGE2                  3
#define FTR_SCANNER_FEATURE_SERIAL_NUMBER               4
#define FTR_SCANNER_FEATURE_LONG_IMAGE                  5
#define FTR_SCANNER_FEATURE_IS_CALIBRATED               6
#define FTR_SCANNER_FEATURE_IS_LFD_CALIBRATED           7
#define FTR_SCANNER_FEATURE_ROLL                        8
#define FTR_SCANNER_FEATURE_ENCRYPTION                  9

#define FTR_POWER_EVENT_SLEEP                           0x00000001
#define FTR_POWER_EVENT_SESSION_DISCONNECT              0x00000002
#define FTR_POWER_EVENT_SESSION_LOGOFF                  0x00000004
#define FTR_POWER_EVENT_LOGGING_OFF                     0x00000008
#define FTR_POWER_EVENT_SHUTDOWN                        0x00000010
#define FTR_POWER_EVENT_LOCK                            0x00000020

#define FTR_POWER_EVENT_ALL                             0xFFFFFFFF
#define FTR_POWER_EVENT_DISABLE_ALL                     FTR_POWER_EVENT_ALL, 0
#define FTR_POWER_EVENT_ENABLE_ALL                      FTR_POWER_EVENT_ALL, FTR_POWER_EVENT_ALL

#define FTR_TIMEOUT_INFINITE                            0xFFFFFFFF

#define FTR_REGISTRY_INDEX_LUM_AVERAGE                  0

#define FTR_PROPERTY_NUMBER_OF_IMAGE_SIZES              1
#define FTR_PROPERTY_LFD_LEVEL                          2
#define FTR_PROPERTY_LFD_SW_1_CALCULATED_DATA           3
#define FTR_PROPERTY_LFD_SW_1_PARAM                     4
#define FTR_PROPERTY_LFD_SW_1_RESERVED                  5
#define FTR_PROPERTY_LFD_SW_2_CALCULATED_DATA           6
#define FTR_PROPERTY_LFD_SW_2_PARAM                     7
#define FTR_PROPERTY_LFD_D_SW_2_CALCULATED_DATA         8
#define FTR_PROPERTY_ENCRYPTION                         9
#define FTR_PROPERTY_ENCRYPTED_RAW_IMAGE_PTR            10
#define FTR_PROPERTY_ENCRYPTED_RAW_IMAGE_SIZE           11

#define FTR_PROPERTY_ENCRYPTED_DEVICE_ROOT_CERTIFICATE_CTX   12
#define FTR_PROPERTY_ENCRYPTED_DEVICE_SRV_CERTIFICATE_CTX	 13

typedef struct FTR_PACKED __FTRSCAN_PROPERTY_NUMBER_OF_IMAGE_SIZES
{
    int                                 nNumberOfImagesSizes;
} FTRSCAN_PROPERTY_NUMBER_OF_IMAGE_SIZES, *PFTRSCAN_PROPERTY_NUMBER_OF_IMAGE_SIZES;

typedef struct FTR_PACKED __FTRSCAN_PROPERTY_LFD_LEVEL
{
    FTR_DWORD                           dwLfdLevel;
} FTRSCAN_PROPERTY_LFD_LEVEL, *PFTRSCAN_PROPERTY_LFD_LEVEL;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_LFD_SW_1_DATA
{
    FTR_DWORD                           dwStrength;
} FTRSCAN_PROPERTY_LFD_SW_1_DATA, *PFTRSCAN_PROPERTY_LFD_SW_1_DATA;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_LFD_SW_1_PARAM
{
    FTR_DWORD                           dwStrength;
} FTRSCAN_PROPERTY_LFD_SW_1_PARAM, *PFTRSCAN_PROPERTY_LFD_SW_1_PARAM;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_LFD_SW_2_DATA
{
    FTR_DWORD                           dwScore;
} FTRSCAN_PROPERTY_LFD_SW_2_DATA, *PFTRSCAN_PROPERTY_LFD_SW_2_DATA;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_LFD_SW_2_PARAM
{
    FTR_DWORD                           dwScore;
} FTRSCAN_PROPERTY_LFD_SW_2_PARAM, *PFTRSCAN_PROPERTY_LFD_SW_2_PARAM;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_ENCRYPTION
{
    int                            bEnable;
} FTRSCAN_PROPERTY_ENCRYPTION, *PFTRSCAN_PROPERTY_ENCRYPTION;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_ENCRYPTED_RAW_IMAGE_PTR
{
    FTR_PVOID                           pBuffer;
    FTR_DWORD                           dwBufferSize;
} FTRSCAN_PROPERTY_ENCRYPTED_RAW_IMAGE_PTR, *PFTRSCAN_PROPERTY_ENCRYPTED_RAW_IMAGE_PTR;

typedef struct FTR_PACKED _FTRSCAN_PROPERTY_ENCRYPTED_RAW_IMAGE_SIZE
{
    FTR_DWORD                           dwSize;
} FTRSCAN_PROPERTY_ENCRYPTED_RAW_IMAGE_SIZE, *PFTRSCAN_PROPERTY_ENCRYPTED_RAW_IMAGE_SIZE;

#define FTR_ROLL_DIRECTION_NOT_DEFINED                  0
#define FTR_ROLL_DIRECTION_FROM_LEFT_TO_RIGHT           1
#define FTR_ROLL_DIRECTION_FROM_RIGHT_TO_LEFT           2

#define FTR_ROLL_FRAME_PARAM_FLAG_NOT_CALIBRATED        0x00000001
#define FTR_ROLL_FRAME_PARAM_FLAG_INDEX                 0x00000002
#define FTR_ROLL_FRAME_PARAM_FLAG_DOSE                  0x00000004
#define FTR_ROLL_FRAME_PARAM_FLAG_CONRAST               0x00000008

#define FTR_ROLL_RESULT_OK                              0
#define FTR_ROLL_RESULT_REVERSE_ROLLING                 1
#define FTR_ROLL_RESULT_TOO_FAST_ROLLING                2
#define FTR_ROLL_RESULT_SLIPPAGE_AREAS                  3
#define FTR_ROLL_RESULT_BREAK                           4

typedef struct FTR_PACKED __FTRSCAN_ROLL_FRAME_PARAMETERS
{
    FTR_DWORD                           dwSize;
    FTR_DWORD                           dwFlags;
    FTR_DWORD                           dwStatus;
    FTR_DWORD                           dwRollingResult;
    FTR_DWORD                           dwDirection;
    FTR_DWORD                           dwFrameIndex;
    FTR_DWORD                           dwFrameDose;
    FTR_DWORD                           dwFrameContrast;
    FTR_DWORD                           dwFrameTimeMs;
} FTRSCAN_ROLL_FRAME_PARAMETERS, *PFTRSCAN_ROLL_FRAME_PARAMETERS;

#define FTR_ROLL_CB_REASON_PUT_FINGER                   0x00000001
#define FTR_ROLL_CB_REASON_REMOVE_FINGER                0x00000002
#define FTR_ROLL_CB_REASON_PROCESSING                   0x00000003
#define FTR_ROLL_CB_REASON_BEFORE_POSTPROCESSING        0x00000004
#define FTR_ROLL_CB_REASON_POSTPROCESSING               0x00000005
#define FTR_ROLL_CB_REASON_AFTER_POSTPROCESSING         0x00000006
#define FTR_ROLL_CB_REASON_STARTED                      0x00000007
#define FTR_ROLL_CB_REASON_ABORTED                      0x00000008
#define FTR_ROLL_CB_REASON_KEEP_EMPTY                   0x00000009

typedef struct FTR_PACKED __FTRSCAN_ROLL_CB_OPERATION_DIODES_STATUS
{
    FTR_BYTE                            byGreenDiodeStatus;
    FTR_BYTE                            byRedDiodeStatus;
} FTRSCAN_ROLL_CB_OPERATION_DIODES_STATUS, *PFTRSCAN_ROLL_CB_OPERATION_DIODES_STATUS;

typedef struct FTR_PACKED __FTRSCAN_ROLL_CB_OPERATION_PF_STATUS
{
    FTR_DWORD                           dwFlags;
    FTR_DWORD                           dwToggleSet;
    FTR_DWORD                           dwPeriod;
    FTR_DWORD                           dwSetFlag;      /* 0 or 1 */
} FTRSCAN_ROLL_CB_OPERATION_PF_STATUS, *PFTRSCAN_ROLL_CB_OPERATION_PF_STATUS;

#define FTR_ROLL_CB_OPERATION_SET_DIODES_STATUS         0x00000001
#define FTR_ROLL_CB_OPERATION_SET_GET_PIN_STATUS        0x00000002

#define FTR_LFD_MODE_HW                                 0x00000001
#define FTR_LFD_MODE_SW_1                               0x00000002
#define FTR_LFD_MODE_SW_2                               0x00000004

#define FTR_LFD_MODE_SW_1_MAX_STRENGTH                  9

#define FTR_LFD_MODE_SW_2_MOST_LIKELY_TO_BE_FAKE        5

#define FTR_LFD_LEVEL_1                                 FTR_LFD_MODE_HW  /* default */
#define FTR_LFD_LEVEL_2                                 (FTR_LFD_MODE_HW | FTR_LFD_MODE_SW_1)
#define FTR_LFD_LEVEL_3                                 (FTR_LFD_MODE_HW | FTR_LFD_MODE_SW_2)
#define FTR_LFD_LEVEL_MAX                               (FTR_LFD_MODE_HW | FTR_LFD_MODE_SW_1 | FTR_LFD_MODE_SW_2)

typedef struct FTR_PACKED __FTRSCAN_DEVICE_INIT_CTX
{
    FTR_UINT32 dwCtxSize;
    FTR_UINT32 dwInitFlags;
} FTRSCAN_DEVICE_INIT_CTX, *PFTRSCAN_DEVICE_INIT_CTX;

#define FTR_DEVICE_INIT_FLAGS_DISABLE_ENCRIPTION        0x00000001

#ifdef __ANDROID_API__
#include <jni.h>

#define FTR_ANDROID_CTX_VERSION_1 (1)
#define FTR_ANDROID_CTX_VERSION_2 (2)

#define FTR_ANDROID_CTX_FLAG_GLB_DONE 0x00000001

typedef struct __ANDROID_CTX
{
    jobject io_ctx;
    jobject zero_field;
    FTR_DWORD ctx_version;
    FTR_DWORD ctx_flags;

} ANDROID_CTX, *PANDROID_CTX;

JNIEXPORT jint JNICALL JNI_OnLoad( JavaVM *jvm, void *reserved );

#endif

#if defined( WINAPI_FAMILY_APP ) && defined(METRO_USB_DEV_API)

#include <Windows.h>
#include <deviceaccess.h>

#define FTR_METRO_API_USBAPI_CTX_VERSION_1 (1)

typedef struct __METRO_API_USBAPI_CTX
{
    FTR_UINT32 ctx_version;
    Windows::Devices::Usb::UsbDevice^ usb_dev;
} METRO_API_USBAPI_CTX, *PMETRO_API_USBAPI_CTX;

#endif

#define FTR_DEVICEIOTRANSFER_SIGNATURE                  0x4654

typedef int( *PFTRDEVICEIOTRANSFERCB )( FTR_PVOID pDeviceSpecificContext );

typedef struct FTR_PACKED _FTR_DEVICEIOTRANSFER
{
    FTR_WORD                            wSignature;
    FTR_BYTE                            byDeviceCompatibility;
    FTR_DWORD                           dwDeviceSpecificValue;
    FTR_PVOID                           pInData;
    int                                 nSizeInData;
    FTR_PVOID                           pOutData;
    int                                 nSizeOutData;
    FTR_PVOID                           pRetValue;
    int                                 nSizeRetValue;
    PFTRDEVICEIOTRANSFERCB              pfnCallbackProc;
    FTR_PVOID                           pDeviceSpecificContext;
} FTR_DEVICEIOTRANSFER, *PFTR_DEVICEIOTRANSFER;

typedef FTR_PVOID( FTR_CALLBACK *PFTRSIMOPENDEVICE )( );
typedef int( FTR_CALLBACK *PFTRSIMDEVICEDATAEXCHANGE )( FTR_PVOID pHandle, int nPortionLength, FTR_PVOID pOutData, int nOutDataLen, FTR_PVOID pInData, int nInDataLen, int bForceKeepOpened, int bUseInEndPointMaxSize );
typedef int( FTR_CALLBACK *PFTRSIMDEVICEDATAEXCHANGEEND )( FTR_PVOID pHandle );
typedef void ( FTR_CALLBACK *PFTRSIMCLOSEDEVICE )( FTR_PVOID * pHandle );
typedef int( FTR_CALLBACK *PFTRSIMGETDEVICEINFO )( FTR_PVOID pHandle, FTR_PVOID pParameters );

typedef struct __FTRSCAN_SIM_CONTEXT
{
    FTR_DWORD dwSize;

    PFTRSIMOPENDEVICE pfOpenDevice;
    PFTRSIMCLOSEDEVICE pfCloseDevice;

    PFTRSIMDEVICEDATAEXCHANGE pfDeviceDataExchange;
    PFTRSIMDEVICEDATAEXCHANGEEND pfDeviceDataExchangeEnd;

    PFTRSIMGETDEVICEINFO pfDeviceGetInfo;

} FTRSCAN_SIM_CONTEXT, *PFTRSCAN_SIM_CONTEXT;

#if defined(__WIN32__)
#pragma pack(pop)
#endif

void * ftrScanOpenDevice();
void * ftrScanOpenDeviceOnInterface( int nInterface );
void * ftrScanOpenDeviceWithIoContext( FTR_PVOID pContext );
void * ftrScanOpenDeviceWithParameters( int nInterface, PFTRSCAN_DEVICE_INIT_CTX pInitContext, FTR_PVOID pIoContext );

void ftrScanCloseDevice( void * ftrHandle );
int ftrScanSetOptions( void * ftrHandle, FTR_DWORD dwMask, FTR_DWORD dwFlags );
int ftrScanGetOptions( void * ftrHandle, FTR_PDWORD lpdwFlags );
int ftrScanGetDeviceInfo( void * ftrHandle, PFTRSCAN_DEVICE_INFO pDeviceInfo );

int ftrScanGetInterfaces( PFTRSCAN_INTERFACES_LIST pInterfaceList );
int ftrSetBaseInterface( int nBaseInterface );
int ftrGetBaseInterfaceNumber();
int ftrSetLoggingFacilityLevel( FTR_DWORD dwLogMask, FTR_DWORD dwLogLevel, char *lpFileName );

FTR_DWORD ftrScanGetLastError();
void ftrScanSetLastError( FTR_DWORD dwErrCode );

int ftrScanGetVersion( void * ftrHandle, PFTRSCAN_VERSION_INFO pVersionInfo );
int ftrScanIsScannerFeaturePresent( void * ftrHandle, int nScannerFeature, FTR_PBOOL pIsPresent );

int ftrScanGetFakeReplicaInterval( double *pdblMinFakeReplicaValue, double *pdblMaxFakeReplicaValue );
void ftrScanSetFakeReplicaInterval( double dblMinFakeReplicaValue, double dblMaxFakeReplicaValue );

int ftrScanGetLFDParameters( PFTRSCAN_LFD_CONSTANTS pLFDParameters );
int ftrScanSetLFDParameters( PFTRSCAN_LFD_CONSTANTS pLFDParameters );
int ftrScanGetScanParameters( void * ftrHandle, FTR_DWORD dwParamCode, FTR_PVOID pOutBuffer );

int ftrScanGetImageSize( void * ftrHandle, PFTRSCAN_IMAGE_SIZE pImageSize );
int ftrScanGetImage( void * ftrHandle, int nDose, FTR_PVOID pBuffer );
int ftrScanGetImage2( void * ftrHandle, int nDose, FTR_PVOID pBuffer );
int ftrScanGetFuzzyImage( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanGetBacklightImage( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanGetDarkImage( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanGetImageByVariableDose( void * ftrHandle, int nVariableDose, FTR_PVOID pBuffer );
int ftrScanGet4in1Image( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanGetImageByVariableDoseEx( void * ftrHandle, int nVariableDose, FTR_BYTE byLights, PFTRSCAN_VAR_DOSE_EXTRA_PARAMS pExtraParams, FTR_PVOID pBuffer );

int ftrScanGetRawImageSize( void * ftrHandle, PFTRSCAN_IMAGE_SIZE pImageSize );
int ftrScanGetRawImageByVariableDose( void * ftrHandle, int nVariableDose, FTR_PVOID pBuffer );
int ftrScanGetRawBacklightImage( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanGetRawDarkImage( void * ftrHandle, FTR_PVOID pBuffer );

int ftrScanIsFingerPresent( void * ftrHandle, PFTRSCAN_FRAME_PARAMETERS pFrameParameters );
int ftrScanGetFrame( void * ftrHandle, FTR_PVOID pBuffer, PFTRSCAN_FRAME_PARAMETERS pFrameParameters );

int ftrScanSave7Bytes( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanRestore7Bytes( void * ftrHandle, FTR_PVOID pBuffer );

int ftrScanGetExtMemorySize( void * ftrHandle, int *pnSize );
int ftrScanSaveExtMemory( void * ftrHandle, FTR_PVOID pBuffer, int nOffset, int nCount );
int ftrScanRestoreExtMemory( void * ftrHandle, FTR_PVOID pBuffer, int nOffset, int nCount );

int ftrScanGetSerialNumber( void * ftrHandle, FTR_PVOID pBuffer );
int ftrScanSaveSerialNumber( void * ftrHandle, FTR_PVOID pReserved );

int ftrScanGetFirmwareMemorySize( void * ftrHandle, int *pnSize );
int ftrScanSaveFirmwareMemory( void * ftrHandle, FTR_PVOID pBuffer, int nOffset, int nCount );
int ftrScanRestoreFirmwareMemory( void * ftrHandle, FTR_PVOID pBuffer, int nOffset, int nCount );

int ftrScanGetCalibrationConstants( void * ftrHandle, FTR_PBYTE pbyIRConst, FTR_PBYTE pbyFuzzyConst );
int ftrScanStoreCalibrationConstants( void * ftrHandle, FTR_BYTE byIRConst, FTR_BYTE byFuzzyConst, int bBurnToFlash );

int ftrScanGetFakeReplicaParameters( void * ftrHandle, PFTRSCAN_FAKE_REPLICA_PARAMETERS pFakeReplicaParams );
int ftrScanGetFakeReplicaBuffer( void * ftrHandle, PFTRSCAN_FAKE_REPLICA_BUFFER pFakeReplicaBuffer );

int ftrScanSetNewAuthorizationCode( void * ftrHandle, FTR_PVOID pSevenBytesAuthorizationCode );
int ftrScanSaveSecret7Bytes( void * ftrHandle, FTR_PVOID pSevenBytesAuthorizationCode, FTR_PVOID pBuffer );
int ftrScanRestoreSecret7Bytes( void * ftrHandle, FTR_PVOID pSevenBytesAuthorizationCode, FTR_PVOID pBuffer );

int ftrScanSetDiodesStatus( void * ftrHandle, FTR_BYTE byGreenDiodeStatus, FTR_BYTE byRedDiodeStatus );
int ftrScanGetDiodesStatus( void * ftrHandle, FTR_PBOOL pbIsGreenDiodeOn, FTR_PBOOL pbIsRedDiodeOn );

int ftrScanSave7ControlBytes( void * ftrHandle, FTR_PVOID pBuffer, int bBurnToFlash );
int ftrScanRestore7ControlBytes( void * ftrHandle, FTR_PVOID pBuffer );

int ftrScanRollStart( void * ftrHandle );
int ftrScanRollStarWithVariableDose( void * ftrHandle, int nVariableDose );
int ftrScanRollRawStart( void * ftrHandle );
int ftrScanRollRawStarWithVariableDose( void * ftrHandle, int nVariableDose );
int ftrScanRollAbort( void * ftrHandle, int bSynchronous );
int ftrScanRollGetImage( void * ftrHandle, FTR_PVOID pBuffer, FTR_DWORD dwMilliseconds );
int ftrScanRollGetFrameParameters( void * ftrHandle, PFTRSCAN_ROLL_FRAME_PARAMETERS pFrameParameters, FTR_PVOID pBuffer, FTR_DWORD dwMilliseconds );
typedef int( FTR_CALLBACK *PFTRROLLFNCB )( FTR_PVOID pUserContext, FTR_DWORD dwRollCallbackReason, FTR_PVOID pFtrContext, FTR_PVOID pReasonCtx );
int ftrScanRollSetCallBackFn( void * ftrHandle, PFTRROLLFNCB pUserCbFb, FTR_PVOID pUserContext );
int ftrScanRollDoOperationFromCb( FTR_PVOID pFtrContext, FTR_DWORD dwRollCbOperation, FTR_PVOID pRollCbOperationParam );

int ftrScanChangeSystemNotification( FTR_DWORD dwMask, FTR_DWORD dwFlags );
int ftrScanGlobalSetOptions( FTR_DWORD dwOption, FTR_PVOID pOptionData );
int ftrScanGlobalGetOptions( FTR_DWORD dwOption, FTR_PVOID pOptionData );

int ftrScanGetStripImageSize( void * ftrHandle, PFTRSCAN_IMAGE_SIZE pImageSize );
int ftrScanGetStripImageByVariableDose( void * ftrHandle, int nVariableDose, FTR_PVOID pBuffer );
int ftrScanGetRegistryValues( void * ftrHandle, FTR_PVOID pBuffer );

int ftrScanConvertRawToFinalImage( void * ftrHandle, FTR_PVOID pRawImageBuffer, FTR_PVOID pFinalImageBuffer, int nDose );

int ftrSweepGetSlice( void * ftrHandle, FTR_PVOID pBuffer );
int ftrSweepGetMultipleSlices( void * ftrHandle, int nSlices, FTR_PVOID pBuffer );

int ftrScanControlPin3( void * ftrHandle, FTR_DWORD *pdwParam1, FTR_DWORD dwParam2, FTR_DWORD dwPeriod );
int ftrScanGetButtonState( void * ftrHandle, FTR_DWORD *pdwParam1 );
int ftrScanMainLEDsTimeout( void * ftrHandle, FTR_DWORD *pwdParam1, FTR_BYTE byFlag );

void ftrSetGlobalDeviceSync( int fSet );

int ftrSweepGetSlice( void * ftrHandle, FTR_PVOID pBuffer );

int ftrInternalDeviceIoExchange( void * ftrHandle, PFTR_DEVICEIOTRANSFER pDeviceIoTransferData );

int ftrScanGetProperty( void * ftrHandle, int nProperty, FTR_PVOID pPropertyData );
int ftrScanGetImageSizes( void * ftrHandle, PFTRSCAN_IMAGE_SIZE pArrayOfImageSizes );
int ftrScanGetImageOfSpecificSize( void * ftrHandle, int nVariableDose, FTR_BYTE byLights, int nWidth, int nHeight, FTR_PVOID pBuffer );
int ftrScanGetImageOfSpecificSizeEx( void * ftrHandle, int nVariableDose, FTR_BYTE byLights, int nWidth, int nHeight, int nFrames, FTR_PVOID pBuffer );
int ftrScanGetImageOfSpecificSize2( void * ftrHandle, int nVariableDose, FTR_BYTE byLights, int nWidth, int nHeight, int nFrames, int nOffsetX, int nOffsetY, FTR_PVOID pBuffer );
int ftrScanSetProperty( void * ftrHandle, int nProperty, FTR_PVOID pPropertyData );

int ftrScanGetPropertySize( void * ftrHandle, int nProperty, FTR_DWORD* propSize );

void * ftrScanOpenDeviceWithSimContext( PFTRSCAN_SIM_CONTEXT simContext );

#if !defined(_WIN32_WCE)
int ftrCertAddPublicKeyContextToStore( FTR_CERTCONTEXT publicKeyContext, FTR_UINT32 nFlags );
int ftrCertAddEncodedPublicKeyToStore( FTR_UINT32 nPublicKeyEncodingType, FTR_PBYTE pPublicKeyEncoded, FTR_UINT32 nPublicKeyEncodedSize, FTR_UINT32 nFlags, FTR_CERTCONTEXT *publicKeyContext );
int ftrCertDeletePublicKeyFromStore( FTR_CERTCONTEXT publicKeyContext );
FTR_CERTCONTEXT ftrCertEnumPublicKeysInStore( FTR_CERTCONTEXT previousPublicKey );
int ftrCertClearStore();
int ftrCertRestoreDefaultStore();
FTR_CERTCONTEXT ftrCertFindPublicKeyInStore( FTR_UINT32 nFindType, const FTR_PVOID pFindParam, FTR_CERTCONTEXT previousPublicKey );
FTR_CERTCONTEXT ftrCertCreatePublicKeyContext( FTR_UINT32 nPublicKeyEncodingType, FTR_PBYTE pPublicKeyEncoded, FTR_UINT32 nPublicKeyEncodedSize );
int ftrCertGetPublicKeyContextProperty( FTR_CERTCONTEXT publicKeyContext, FTR_UINT32 nPropId, FTR_PVOID pData, FTR_UINT32 *pDataSize );
void ftrCertFreePublicKeyContext( FTR_CERTCONTEXT publicKeyContext );
FTR_BOOL ftrCertVerify(FTR_CERTCONTEXT pCheckCtx, FTR_CERTCONTEXT pVerifyCtx, FTR_PBYTE calcBuffer, FTR_UINT32 calcBufferSize);
#endif

#ifdef __cplusplus
}
#endif

#endif // __FUTRONIC_SCAN_API_H__
