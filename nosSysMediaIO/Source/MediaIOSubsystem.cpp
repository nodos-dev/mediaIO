// Copyright MediaZ Teknoloji A.S. All Rights Reserved.
#include <Nodos/SubsystemAPI.h>

#include <nosMediaIO/nosMediaIO.h>

NOS_INIT_WITH_MIN_REQUIRED_MINOR(0); // APITransition: Reminder that this should be reset after next major!

NOS_BEGIN_IMPORT_DEPS()
NOS_END_IMPORT_DEPS()

namespace nos::sys::mediaio
{
std::unordered_map<uint32_t, nosMediaIOSubsystem*> GExportedSubsystemVersions;

const char* NOSAPI_CALL GetFrameGeometryName(nosMediaIOFrameGeometry geometry)
{
	if (geometry < NOS_MEDIAIO_FRAME_GEOMETRY_MIN || geometry > NOS_MEDIAIO_FRAME_GEOMETRY_MAX)
		return NOS_MEDIAIO_FRAME_GEOMETRY_NAMES[NOS_MEDIAIO_FRAME_GEOMETRY_INVALID];
	return NOS_MEDIAIO_FRAME_GEOMETRY_NAMES[geometry];
}

const char* NOSAPI_CALL GetFrameRateName(nosMediaIOFrameRate frameRate)
{
	if (frameRate < NOS_MEDIAIO_FRAME_RATE_MIN || frameRate > NOS_MEDIAIO_FRAME_RATE_MAX)
		return NOS_MEDIAIO_FRAME_RATE_NAMES[NOS_MEDIAIO_FRAME_RATE_INVALID];
	return NOS_MEDIAIO_FRAME_RATE_NAMES[frameRate];
}

const char* NOSAPI_CALL GetPixelFormatName(nosMediaIOPixelFormat pixelFormat)
{
	if (pixelFormat < NOS_MEDIAIO_PIXEL_FORMAT_MIN || pixelFormat > NOS_MEDIAIO_PIXEL_FORMAT_MAX)
		return NOS_MEDIAIO_PIXEL_FORMAT_NAMES[NOS_MEDIAIO_PIXEL_FORMAT_INVALID];
	return NOS_MEDIAIO_PIXEL_FORMAT_NAMES[pixelFormat];
}

nosMediaIOFrameGeometry NOSAPI_CALL GetFrameGeometryFromString(const char* str)
{
	for (size_t i = NOS_MEDIAIO_FRAME_GEOMETRY_MIN; i <= NOS_MEDIAIO_FRAME_GEOMETRY_MAX; ++i)
	{
		if (strcmp(str, NOS_MEDIAIO_FRAME_GEOMETRY_NAMES[i]) == 0)
			return static_cast<nosMediaIOFrameGeometry>(i);
	}
	return NOS_MEDIAIO_FRAME_GEOMETRY_INVALID;
}

nosMediaIOFrameRate NOSAPI_CALL GetFrameRateFromString(const char* str)
{
	for (size_t i = NOS_MEDIAIO_FRAME_RATE_MIN; i <= NOS_MEDIAIO_FRAME_RATE_MAX; ++i)
	{
		if (strcmp(str, NOS_MEDIAIO_FRAME_RATE_NAMES[i]) == 0)
			return static_cast<nosMediaIOFrameRate>(i);
	}
	return NOS_MEDIAIO_FRAME_RATE_INVALID;
}

nosMediaIOPixelFormat NOSAPI_CALL GetPixelFormatFromString(const char* str)
{
	for (size_t i = NOS_MEDIAIO_PIXEL_FORMAT_MIN; i <= NOS_MEDIAIO_PIXEL_FORMAT_MAX; ++i)
	{
		if (strcmp(str, NOS_MEDIAIO_PIXEL_FORMAT_NAMES[i]) == 0)
			return static_cast<nosMediaIOPixelFormat>(i);
	}
	return NOS_MEDIAIO_PIXEL_FORMAT_INVALID;
}
	
// Function implementation
nosResult NOSAPI_CALL GetFrameRateDeltaSeconds(nosMediaIOFrameRate frameRate, nosVec2u* outDeltaSeconds) {
	if (outDeltaSeconds == nullptr)
		return NOS_RESULT_INVALID_ARGUMENT;

	static const std::unordered_map<nosMediaIOFrameRate, nosVec2u> frameRateTable = {
		{NOS_MEDIAIO_FRAME_RATE_2398, {1001, 24000}},
		{NOS_MEDIAIO_FRAME_RATE_24, {1, 24}},
		{NOS_MEDIAIO_FRAME_RATE_25, {1, 25}},
		{NOS_MEDIAIO_FRAME_RATE_2997, {1001, 30000}},
		{NOS_MEDIAIO_FRAME_RATE_30, {1, 30}},
		{NOS_MEDIAIO_FRAME_RATE_4795, {1001, 20000}},
		{NOS_MEDIAIO_FRAME_RATE_48, {1, 48}},
		{NOS_MEDIAIO_FRAME_RATE_50, {1, 50}},
		{NOS_MEDIAIO_FRAME_RATE_5994, {1001, 60000}},
		{NOS_MEDIAIO_FRAME_RATE_60, {1, 60}},
		{NOS_MEDIAIO_FRAME_RATE_9590, {1001, 96000}},
		{NOS_MEDIAIO_FRAME_RATE_96, {1, 96}},
		{NOS_MEDIAIO_FRAME_RATE_100, {1, 100}},
		{NOS_MEDIAIO_FRAME_RATE_11988, {3001, 120000}},
		{NOS_MEDIAIO_FRAME_RATE_120, {1, 120}}
	};

	auto it = frameRateTable.find(frameRate);
	if (it != frameRateTable.end())
	{
		*outDeltaSeconds = it->second;
		return NOS_RESULT_SUCCESS;
	}

	return NOS_RESULT_INVALID_ARGUMENT;
}

nosResult NOSAPI_CALL Get2DFrameResolution(nosMediaIOFrameGeometry geom, nosVec2u* outResolution)
{
	if (outResolution == nullptr)
		return NOS_RESULT_INVALID_ARGUMENT;

	static const std::unordered_map<nosMediaIOFrameGeometry, nosVec2u> frameGeometryTable = {
		{NOS_MEDIAIO_FRAME_GEOMETRY_NTSC, {720, 486}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_PAL, {720, 576}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_HD720, {1280, 720}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_HD1080, {1920, 1080}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_2K, {2048, 1080}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_2KDCI, {2048, 1080}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_4K2160, {3840, 2160}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_4KDCI, {4096, 2160}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_8K4320, {7680, 4320}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_8KDCI, {8192, 4320}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_640x480, {640, 480}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_800x600, {800, 600}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_1440x900, {1440, 900}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_1440x1080, {1440, 1080}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_1600x1200, {1600, 1200}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_1920x1200, {1920, 1200}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_1920x1440, {1920, 1440}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_2560x1440, {2560, 1440}},
		{NOS_MEDIAIO_FRAME_GEOMETRY_2560x1600, {2560, 1600}}
	};

	auto it = frameGeometryTable.find(geom);
	if (it != frameGeometryTable.end())
	{
		*outResolution = it->second;
		return NOS_RESULT_SUCCESS;
	}

	return NOS_RESULT_INVALID_ARGUMENT;
}

nosResult NOSAPI_CALL Export(uint32_t minorVersion, void** outSubsystemContext)
{
	auto it = GExportedSubsystemVersions.find(minorVersion);
	if (it != GExportedSubsystemVersions.end())
	{
		*outSubsystemContext = it->second;
		return NOS_RESULT_SUCCESS;
	}
	nosMediaIOSubsystem* subsystem = new nosMediaIOSubsystem();
	subsystem->GetFrameGeometryName = GetFrameGeometryName;
	subsystem->GetFrameRateName = GetFrameRateName;
	subsystem->GetPixelFormatName = GetPixelFormatName;
	subsystem->GetFrameGeometryFromString = GetFrameGeometryFromString;
	subsystem->GetFrameRateFromString = GetFrameRateFromString;
	subsystem->GetPixelFormatFromString = GetPixelFormatFromString;
	subsystem->GetFrameRateDeltaSeconds = GetFrameRateDeltaSeconds;
	subsystem->Get2DFrameResolution = Get2DFrameResolution;
	*outSubsystemContext = subsystem;
	GExportedSubsystemVersions[minorVersion] = subsystem;
	return NOS_RESULT_SUCCESS;
}

nosResult NOSAPI_CALL Initialize()
{
	return NOS_RESULT_SUCCESS;
}

nosResult NOSAPI_CALL UnloadSubsystem()
{
	return NOS_RESULT_SUCCESS;
}

extern "C"
{
NOSAPI_ATTR nosResult NOSAPI_CALL nosExportSubsystem(nosSubsystemFunctions* subsystemFunctions)
{
	subsystemFunctions->OnRequest = Export;
	subsystemFunctions->Initialize = Initialize;
	subsystemFunctions->OnPreUnloadSubsystem = UnloadSubsystem;
	return NOS_RESULT_SUCCESS;
}
}
}
