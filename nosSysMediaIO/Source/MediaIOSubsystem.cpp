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
	switch (geometry)
	{
	case NOS_MEDIAIO_FG_INVALID: return "Invalid";
	case NOS_MEDIAIO_FG_NTSC: return "NTSC";
	case NOS_MEDIAIO_FG_PAL: return "PAL";
	case NOS_MEDIAIO_FG_HD720: return "HD 720";
	case NOS_MEDIAIO_FG_HD1080: return "HD 1080";
	case NOS_MEDIAIO_FG_2K: return "2K";
	case NOS_MEDIAIO_FG_2KDCI: return "2K DCI";
	case NOS_MEDIAIO_FG_4K2160: return "4K 2160";
	case NOS_MEDIAIO_FG_4KDCI: return "4K DCI";
	case NOS_MEDIAIO_FG_8K4320: return "8K 4320";
	case NOS_MEDIAIO_FG_8KDCI: return "8K DCI";
	case NOS_MEDIAIO_FG_640x480: return "640x480";
	case NOS_MEDIAIO_FG_800x600: return "800x600";
	case NOS_MEDIAIO_FG_1440x900: return "1440x900";
	case NOS_MEDIAIO_FG_1440x1080: return "1440x1080";
	case NOS_MEDIAIO_FG_1600x1200: return "1600x1200";
	case NOS_MEDIAIO_FG_1920x1200: return "1920x1200";
	case NOS_MEDIAIO_FG_1920x1440: return "1920x1440";
	case NOS_MEDIAIO_FG_2560x1440: return "2560x1440";
	case NOS_MEDIAIO_FG_2560x1600: return "2560x1600";
	}
	return "Unknown";
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
