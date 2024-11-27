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
	NOS_MEDIAIO_DIRECTION_INPUT,
	NOS_MEDIAIO_DIRECTION_OUTPUT,
} nosMediaIODirection;

// TODO: Should this be nosVec2u?
typedef enum nosMediaIOFrameGeometry
{
	NOS_MEDIAIO_FG_INVALID,
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
	NOS_MEDIAIO_FG_2560x1600
} nosMediaIOFrameGeometry;

typedef enum nosMediaIOFrameRate
{
	NOS_MEDIAIO_FRAME_RATE_INVALID,
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
	NOS_MEDIAIO_FRAME_RATE_120
} nosMediaIOFrameRate;

typedef enum nosMediaIOPixelFormat
{
	NOS_MEDIAIO_PIXEL_FORMAT_INVALID,
	NOS_MEDIAIO_PIXEL_FORMAT_YCBCR_8BIT,
	NOS_MEDIAIO_PIXEL_FORMAT_YCBCR_10BIT,
} nosMediaIOPixelFormat;

typedef struct nosMediaIOSubsystem {
	const char* (NOSAPI_CALL* GetFrameGeometryName)(nosMediaIOFrameGeometry geometry);
	const char* (NOSAPI_CALL* GetFrameRateName)(nosMediaIOFrameRate frameRate);
	const char* (NOSAPI_CALL* GetPixelFormatName)(nosMediaIOPixelFormat pixelFormat);
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