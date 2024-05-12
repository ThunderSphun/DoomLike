#pragma once

#include <string>
#include "point.hpp"

namespace doomLike {
	class Window {
	public:
		virtual ~Window() = default;

		virtual bool init(const std::string& title, const math::Point<int, 2>& size) = 0;
		virtual bool shutdown() = 0;

		virtual void setClearColor(const math::Point<float, 4>& color) = 0;

		[[nodiscard]] bool shouldClose() const;

		virtual void preDraw() {};
		virtual void postDraw() {};

	protected:
		bool closing = false;
	};
}