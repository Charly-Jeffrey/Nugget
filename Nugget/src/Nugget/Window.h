#pragma once

#include "NGpch.h"

#include "Nugget/Core.h"
#include "Nugget/Events/Event.h"

namespace Nugget {

	// Basic window properties
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Nugget Engine",
			unsigned int width = 1280,
			unsigned int height = 800)
			: Title(title), Width(width), Height(height) 
		{}
	};

	// Window interface
	class NUGGET_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// Has to be implemented per platform
		static Window* Create(const WindowProps& props = WindowProps());
	};
}
