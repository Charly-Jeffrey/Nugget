#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Nugget 
{
	class NUGGET_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Engine log macros
#define NG_CORE_TRACE(...)	::Nugget::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define NG_CORE_INFO(...)	::Nugget::Log::GetEngineLogger()->info(__VA_ARGS__)
#define NG_CORE_WARN(...)	::Nugget::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define NG_CORE_ERROR(...)	::Nugget::Log::GetEngineLogger()->error(__VA_ARGS__)
#define NG_CORE_FATAL(...)	::Nugget::Log::GetEngineLogger()->fatal(__VA_ARGS__)
// Client log macros
#define NG_TRACE(...)		::Nugget::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NG_INFO(...)		::Nugget::Log::GetClientLogger()->info(__VA_ARGS__)
#define NG_WARN(...)		::Nugget::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NG_ERROR(...)		::Nugget::Log::GetClientLogger()->error(__VA_ARGS__)
#define NG_FATAL(...)		::Nugget::Log::GetClientLogger()->fatal(__VA_ARGS__)