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
	NOS_MEDIAIO_FG_INVALID,
	NOS_MEDIAIO_FG_MIN = NOS_MEDIAIO_FG_INVALID,
	NOS_MEDIAIO_FG_NTSC,
	NOS_MEDIAIO_FG_PAL,
	NOS_MEDIAIO_FG_HD720,
	NOS_MEDIAIO_FG_HD1080,
	NOS_MEDIAIO_FG_2K,
	NOS_MEDIAIO_FG_2KDCI,
	NOS_MEDIAIO_FG_4K2160,
	NOS_MEDIAIO_FG_4KDCI,
	NOS_MEDIAIO_FG_8K4320,
	NOS_MEDIAIO_FG_8KDCI,
	NOS_MEDIAIO_FG_640x480,
	NOS_MEDIAIO_FG_800x600,
	NOS_MEDIAIO_FG_1440x900,
	NOS_MEDIAIO_FG_1440x1080,
	NOS_MEDIAIO_FG_1600x1200,
	NOS_MEDIAIO_FG_1920x1200,
	NOS_MEDIAIO_FG_1920x1440,
	NOS_MEDIAIO_FG_2560x1440,
	NOS_MEDIAIO_FG_2560x1600,
	NOS_MEDIAIO_FG_MAX = NOS_MEDIAIO_FG_2560x1600
} nosMediaIOFrameGeometry;

#define NOS_MEDIAIO_FRAME_GEOMETRY_COUNT (NOS_MEDIAIO_FG_MAX - NOS_MEDIAIO_FG_MIN)

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

typedef struct nosMediaIOSubsystem {
	const char* (NOSAPI_CALL* GetFrameGeometryName)(nosMediaIOFrameGeometry geometry);
	const char* (NOSAPI_CALL* GetFrameRateName)(nosMediaIOFrameRate frameRate);
	const char* (NOSAPI_CALL* GetPixelFormatName)(nosMediaIOPixelFormat pixelFormat);
	nosMediaIOFrameGeometry (NOSAPI_CALL* GetFrameGeometryFromString)(const char* str);
	nosMediaIOFrameRate (NOSAPI_CALL* GetFrameRateFromString)(const char* str);
	nosMediaIOPixelFormat (NOSAPI_CALL* GetPixelFormatFromString)(const char* str);
	nosResult (NOSAPI_CALL* GetFrameRateDeltaSeconds)(nosMediaIOFrameRate frameRate, nosVec2u* outDeltaSeconds);
	nosResult (NOSAPI_CALL* Get2DFrameResolution)(nosMediaIOFrameGeometry geometry, nosVec2u* outResolution);
} nosMediaIOSubsystem;

#pragma region Helper Declarations & Macros

// Make sure these are same with nossys file.
#define NOS_MEDIAIO_SUBSYSTEM_NAME "nos.sys.mediaio"
#define NOS_MEDIAIO_SUBSYSTEM_VERSION_MAJOR 1
#define NOS_MEDIAIO_SUBSYSTEM_VERSION_MINOR 0

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