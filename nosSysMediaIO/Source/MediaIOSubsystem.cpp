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
	if (geometry < NOS_MEDIAIO_FG_MIN || geometry > NOS_MEDIAIO_FG_MAX)
		return NOS_MEDIAIO_FRAME_GEOMETRY_NAMES[NOS_MEDIAIO_FG_INVALID];
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
	for (size_t i = NOS_MEDIAIO_FG_MIN; i <= NOS_MEDIAIO_FG_MAX; ++i)
	{
		if (strcmp(str, NOS_MEDIAIO_FRAME_GEOMETRY_NAMES[i]) == 0)
			return static_cast<nosMediaIOFrameGeometry>(i);
	}
	return NOS_MEDIAIO_FG_INVALID;
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
