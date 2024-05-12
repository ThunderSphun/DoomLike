#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

namespace doomLike {
	class GLFW_GLEW_Window : public Window {
	public:
		bool init(const std::string& title, const math::Point<int, 2>& size) override;
		bool shutdown() override;
		void setClearColor(const math::Point<float, 4>& color) override;

		void preDraw() override;
		void postDraw() override;

	private:
		GLFWwindow* window;

		bool initGLFW(const std::string& title, const math::Point<int, 2>& size);
		bool initGLEW();

		static inline std::string getGLFWError();
	};
}