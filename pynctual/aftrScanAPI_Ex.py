from cffi import FFI
import os
import ctypes
import sys
import numpy
from PIL import Image
ffi = FFI()
ffi.cdef("""
typedef unsigned char FTR_BYTE;
void *malloc(size_t size);
void free(void *ptr);
""")
ffi.cdef("""
typedef struct
{
    int                                 nWidth;
    int                                 nHeight;
    int                                 nImageSize;
}  FTRSCAN_IMAGE_SIZE, *PFTRSCAN_IMAGE_SIZE;
typedef struct
{
    int                            bCalculated;
    int                                 nCalculatedSum1;
    int                                 nCalculatedSumFuzzy;
    int                                 nCalculatedSumEmpty;
    int                                 nCalculatedSum2;
    double                              dblCalculatedTremor;
    double                              dblCalculatedValue;
} FTRSCAN_FAKE_REPLICA_PARAMETERS, *PFTRSCAN_FAKE_REPLICA_PARAMETERS;

typedef struct
{
    int                                 nContrastOnDose2;
    int                                 nContrastOnDose4;
    int                                 nDose;
    int                                 nBrightnessOnDose1;
    int                                 nBrightnessOnDose2;
    int                                 nBrightnessOnDose3;
    int                                 nBrightnessOnDose4;
    FTRSCAN_FAKE_REPLICA_PARAMETERS     FakeReplicaParams;
    FTR_BYTE                            Reserved[ 24 ];
} FTRSCAN_FRAME_PARAMETERS, *PFTRSCAN_FRAME_PARAMETERS;

""", packed=True)
ffi.cdef("""


   void * ftrScanOpenDevice();

   int ftrScanGetImageSize(void * ftrHandle, PFTRSCAN_IMAGE_SIZE pImageSize );
   void ftrScanCloseDevice( void * ftrHandle );
   typedef unsigned int FTR_DWORD;
   FTR_DWORD ftrScanGetLastError();
   int ftrScanIsFingerPresent( void * ftrHandle, PFTRSCAN_FRAME_PARAMETERS pFrameParameters );
   int ftrScanGetFrame( void * ftrHandle, void * pBuffer, PFTRSCAN_FRAME_PARAMETERS pFrameParameters );




""")


lib =  ffi.dlopen("./libScanAPI.so")

def PrintErrorMessage( nErrCode ):
    print('Failed to obtain image. ')
    stError
    if nErrCode == 0:
        stError = "OK"
    elif nErrCode == FTR_ERROR_EMPTY_FRAME:
        stError = "- Empty frame -"

    elif nErrCode == FTR_ERROR_MOVABLE_FINGER:
        stError = "- Movable finger -"

    elif nErrCode == FTR_ERROR_NO_FRAME:
        stError = "- Fake finger -"

    elif nErrCode == FTR_ERROR_HARDWARE_INCOMPATIBLE:
        stError = "- Incompatible hardware -"

    elif nErrCode == FTR_ERROR_FIRMWARE_INCOMPATIBLE:
        stError = "- Incompatible firmware -"

    elif nErrCode == FTR_ERROR_INVALID_AUTHORIZATION_CODE:
        stError = "- Invalid authorization code -"
    else:
        stError = "Unknown return code - " + str(nErrCode)
    print(stError)


#driver function

ImageSize =  ffi.new("FTRSCAN_IMAGE_SIZE *")
hDevice = lib.ftrScanOpenDevice()
if hDevice ==  ffi.NULL:
    print('Failed to open device!\n')
err = lib.ftrScanGetImageSize( hDevice, ImageSize)
if (err==0)  :
    print('Failed to get image size\n')
    print(lib.ftrScanGetLastError())
    lib.ftrScanCloseDevice( hDevice )
else:
    print('Image size is ', ImageSize.nImageSize)
    pBuffer = lib.malloc(ImageSize.nImageSize)
    print('Please put your finger on the scanner:\n')
    while (1):
        if lib.ftrScanIsFingerPresent( hDevice, ffi.NULL ):
            break
        for i in range(0,100):
            pass #sleep
    print('Capturing fingerprint ......\n')
    while (1):
        if (lib.ftrScanGetFrame(hDevice, pBuffer, ffi.NULL)):
            print('Done!\nWriting to file......\n')
            #TODO: write_bmp_file( pBuffer, ImageSize.nWidth, ImageSize.nHeight)
            #print(ImageSize.nWidth)
            #print(ImageSize.nHeight)
            #pimg = ffi.new('unsigned char[]')
            pimg = ffi.cast('unsigned char [320][480]', pBuffer)
            result = Image.frombuffer('L', (ImageSize.nWidth, ImageSize.nHeight), ffi.buffer(pBuffer, ImageSize.nImageSize), 'raw')
            result.save('out.bmp')
            break
        else:
            PrintErrorMessage( lib.ftrScanGetLastError() )
            for i in range(0,100):
                pass #sleep

    lib.ftrScanCloseDevice( hDevice )
