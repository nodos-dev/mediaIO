/*
 * Copyright MediaZ Teknoloji A.S. All Rights Reserved.
 */

#ifndef NOS_MEDIAIO_H_INCLUDED
#define NOS_MEDIAIO_H_INCLUDED

#if __cplusplus
extern "C"
{
#endif

#include <Nodos/Types.h>

typedef enum nosMediaIODirection
{
	NOS_MEDIAIO_DIRECTION_OUTPUT,
	NOS_MEDIAIO_DIRECTION_INPUT,
} nosMediaIODirection;

// TODO: Should this be nosVec2u?
typedef enum nosMediaIOFrameGeometry
{
	NOS_MEDIAIO_FRAME_GEOMETRY_INVALID,
	NOS_MEDIAIO_FRAME_GEOMETRY_MIN = NOS_MEDIAIO_FRAME_GEOMETRY_INVALID,
	NOS_MEDIAIO_FRAME_GEOMETRY_NTSC,
	NOS_MEDIAIO_FRAME_GEOMETRY_PAL,
	NOS_MEDIAIO_FRAME_GEOMETRY_HD720,
	NOS_MEDIAIO_FRAME_GEOMETRY_HD1080,
	NOS_MEDIAIO_FRAME_GEOMETRY_2K,
	NOS_MEDIAIO_FRAME_GEOMETRY_2KDCI,
	NOS_MEDIAIO_FRAME_GEOMETRY_4K2160,
	NOS_MEDIAIO_FRAME_GEOMETRY_4KDCI,
	NOS_MEDIAIO_FRAME_GEOMETRY_8K4320,
	NOS_MEDIAIO_FRAME_GEOMETRY_8KDCI,
	NOS_MEDIAIO_FRAME_GEOMETRY_640x480,
	NOS_MEDIAIO_FRAME_GEOMETRY_800x600,
	NOS_MEDIAIO_FRAME_GEOMETRY_1440x900,
	NOS_MEDIAIO_FRAME_GEOMETRY_1440x1080,
	NOS_MEDIAIO_FRAME_GEOMETRY_1600x1200,
	NOS_MEDIAIO_FRAME_GEOMETRY_1920x1200,
	NOS_MEDIAIO_FRAME_GEOMETRY_1920x1440,
	NOS_MEDIAIO_FRAME_GEOMETRY_2560x1440,
	NOS_MEDIAIO_FRAME_GEOMETRY_2560x1600,
	NOS_MEDIAIO_FRAME_GEOMETRY_MAX = NOS_MEDIAIO_FRAME_GEOMETRY_2560x1600
} nosMediaIOFrameGeometry;

#define NOS_MEDIAIO_FRAME_GEOMETRY_COUNT (NOS_MEDIAIO_FRAME_GEOMETRY_MAX - NOS_MEDIAIO_FRAME_GEOMETRY_MIN)

inline const char* NOS_MEDIAIO_FRAME_GEOMETRY_NAMES[] = {
	"INVALID",
	"NTSC",
	"PAL",
	"HD 720",
	"HD 1080",
	"2K",
	"2K DCI",
	"4K 2160",
	"4K DCI",
	"8K 4320",
	"8K DCI",
	"640x480",
	"800x600",
	"1440x900",
	"1440x1080",
	"1600x1200",
	"1920x1200",
	"1920x1440",
	"2560x1440",
	"2560x1600",
};

typedef struct nosMediaIOFrameGeometryList {
	size_t Count;
	nosMediaIOFrameGeometry Geometries[NOS_MEDIAIO_FRAME_GEOMETRY_COUNT];
} nosMediaIOFrameGeometryList;

typedef enum nosMediaIOFrameRate
{
	NOS_MEDIAIO_FRAME_RATE_INVALID,
	NOS_MEDIAIO_FRAME_RATE_MIN = NOS_MEDIAIO_FRAME_RATE_INVALID,
	NOS_MEDIAIO_FRAME_RATE_2398,
	NOS_MEDIAIO_FRAME_RATE_24,
	NOS_MEDIAIO_FRAME_RATE_25,
	NOS_MEDIAIO_FRAME_RATE_2997,
	NOS_MEDIAIO_FRAME_RATE_30,
	NOS_MEDIAIO_FRAME_RATE_4795,
	NOS_MEDIAIO_FRAME_RATE_48,
	NOS_MEDIAIO_FRAME_RATE_50,
	NOS_MEDIAIO_FRAME_RATE_5994,
	NOS_MEDIAIO_FRAME_RATE_60,
	NOS_MEDIAIO_FRAME_RATE_9590,
	NOS_MEDIAIO_FRAME_RATE_96,
	NOS_MEDIAIO_FRAME_RATE_100,
	NOS_MEDIAIO_FRAME_RATE_11988,
	NOS_MEDIAIO_FRAME_RATE_120,
	NOS_MEDIAIO_FRAME_RATE_MAX = NOS_MEDIAIO_FRAME_RATE_120
} nosMediaIOFrameRate;

#define NOS_MEDIAIO_FRAME_RATE_COUNT (NOS_MEDIAIO_FRAME_RATE_MAX - NOS_MEDIAIO_FRAME_RATE_MIN)

inline const char* NOS_MEDIAIO_FRAME_RATE_NAMES[] = {
	"INVALID",
	"23.98",
	"24",
	"25",
	"29.97",
	"30",
	"47.95",
	"48",
	"50",
	"59.94",
	"60",
	"95.90",
	"96",
	"100",
	"119.88",
	"120"
};

typedef struct nosMediaIOFrameRateList {
	size_t Count;
	nosMediaIOFrameRate FrameRates[NOS_MEDIAIO_FRAME_RATE_COUNT];
} nosMediaIOFrameRateList;

typedef enum nosMediaIOPixelFormat
{
	NOS_MEDIAIO_PIXEL_FORMAT_INVALID,
	NOS_MEDIAIO_PIXEL_FORMAT_MIN = NOS_MEDIAIO_PIXEL_FORMAT_INVALID,
	NOS_MEDIAIO_PIXEL_FORMAT_YCBCR_8BIT,
	NOS_MEDIAIO_PIXEL_FORMAT_YCBCR_10BIT,
	NOS_MEDIAIO_PIXEL_FORMAT_MAX = NOS_MEDIAIO_PIXEL_FORMAT_YCBCR_10BIT
} nosMediaIOPixelFormat;

#define NOS_MEDIAIO_PIXEL_FORMAT_COUNT (NOS_MEDIAIO_PIXEL_FORMAT_MAX - NOS_MEDIAIO_PIXEL_FORMAT_MIN)

inline const char* NOS_MEDIAIO_PIXEL_FORMAT_NAMES[] = {
	"INVALID",
	"YCbCr 8-bit",
	"YCbCr 10-bit"
};

typedef struct nosMediaIOPixelFormatList {
	size_t Count;
	nosMediaIOPixelFormat PixelFormats[NOS_MEDIAIO_PIXEL_FORMAT_COUNT];
} nosMediaIOPixelFormatList;

typedef enum nosMediaIOVideoScanType
{
	NOS_MEDIAIO_VIDEO_SCAN_TYPE_INVALID,
	NOS_MEDIAIO_VIDEO_SCAN_TYPE_MIN = NOS_MEDIAIO_VIDEO_SCAN_TYPE_INVALID,
	NOS_MEDIAIO_VIDEO_PROGRESSIVE_SCAN,
	NOS_MEDIAIO_VIDEO_INTERLACED_SCAN,
	NOS_MEDIAIO_VIDEO_SCAN_TYPE_MAX = NOS_MEDIAIO_VIDEO_INTERLACED_SCAN
} nosMediaIOVideoScanType;

inline const char* NOS_MEDIAIO_VIDEO_SCAN_TYPE_NAMES[] = {
	"INVALID",
	"Progressive",
	"Interlaced"
};

typedef struct nosMediaIOVideoScanTypeList {
	size_t Count;
	nosMediaIOVideoScanType ScanTypes[2];
} nosMediaIOVideoScanTypeList;

typedef enum nosMediaIOInterlacedFieldType
{
	NOS_MEDIAIO_INTERLACED_FIELD_TYPE_INVALID,
	NOS_MEDIAIO_INTERLACED_FIELD_TYPE_MIN = NOS_MEDIAIO_INTERLACED_FIELD_TYPE_INVALID,
	NOS_MEDIAIO_INTERLACED_EVEN_FIELD,
	NOS_MEDIAIO_INTERLACED_ODD_FIELD,
	NOS_MEDIAIO_INTERLACED_FIELD_TYPE_MAX = NOS_MEDIAIO_INTERLACED_ODD_FIELD
} nosMediaIOInterlacedFieldType;

typedef struct nosMediaIOSubsystem {
	const char* (NOSAPI_CALL* GetFrameGeometryName)(nosMediaIOFrameGeometry geometry);
	const char* (NOSAPI_CALL* GetFrameRateName)(nosMediaIOFrameRate frameRate);
	const char* (NOSAPI_CALL* GetPixelFormatName)(nosMediaIOPixelFormat pixelFormat);
	nosMediaIOFrameGeometry (NOSAPI_CALL* GetFrameGeometryFromString)(const char* str);
	nosMediaIOFrameRate (NOSAPI_CALL* GetFrameRateFromString)(const char* str);
	nosMediaIOPixelFormat (NOSAPI_CALL* GetPixelFormatFromString)(const char* str);
	nosResult (NOSAPI_CALL* GetFrameRateDeltaSeconds)(nosMediaIOFrameRate frameRate, nosVec2u* outDeltaSeconds);
	nosResult (NOSAPI_CALL* Get2DFrameResolution)(nosMediaIOFrameGeometry geometry, nosVec2u* outResolution);
	const char* (NOSAPI_CALL* GetVideoScanTypeName)(nosMediaIOVideoScanType scanType);
	nosMediaIOVideoScanType (NOSAPI_CALL* GetVideoScanTypeFromString)(const char* str);
} nosMediaIOSubsystem;

#pragma region Helper Declarations & Macros

// Make sure these are same with nossys file.
#define NOS_MEDIAIO_SUBSYSTEM_NAME "nos.sys.mediaio"
#define NOS_MEDIAIO_SUBSYSTEM_VERSION_MAJOR 0
#define NOS_MEDIAIO_SUBSYSTEM_VERSION_MINOR 3

extern struct nosModuleInfo nosMediaIOSubsystemModuleInfo;
extern nosMediaIOSubsystem* nosMediaIO;

#define NOS_MEDIAIO_SUBSYSTEM_INIT()      \
	nosModuleInfo nosMediaIOSubsystemModuleInfo; \
	nosMediaIOSubsystem* nosMediaIO = nullptr;

#define NOS_MEDIAIO_SUBSYSTEM_IMPORT() NOS_IMPORT_DEP(NOS_MEDIAIO_SUBSYSTEM_NAME, nosMediaIOSubsystemModuleInfo, nosMediaIO)

#pragma endregion

#if __cplusplus
}
#endif

#endif