#include <iostream>
#include "impl/glfw_glew_window.hpp"

using namespace doomLike;

bool GLFW_GLEW_Window::init(const std::string& title, const math::Point<int, 2>& size) {
	if (!initGLFW(title, size))
		return false;

	if (!initGLEW())
		return false;



	glfwSwapInterval(1);

	return true;
}

bool GLFW_GLEW_Window::shutdown() {
	glfwDestroyWindow(window);
	glfwTerminate();
	return true;
}

void GLFW_GLEW_Window::setClearColor(const math::Point<float, 4>& color) {
	glClearColor(color.r, color.g, color.b, color.a);
}

void GLFW_GLEW_Window::preDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLFW_GLEW_Window::postDraw() {
	glfwSwapBuffers(window);

	glfwPollEvents();

	if (glfwWindowShouldClose(window))
		closing = true;
}

bool GLFW_GLEW_Window::initGLFW(const std::string& title, const math::Point<int, 2>& size) {
	if (!glfwInit()) {
		std::cerr << getGLFWError() << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

	window = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
	if (!window) {
		std::cerr << getGLFWError() << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	return true;
}

bool GLFW_GLEW_Window::initGLEW() {
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << glewGetErrorString(err) << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}

	return true;
}

std::string GLFW_GLEW_Window::getGLFWError() {
	const char* glfwErrorMsg;
	glfwGetError(&glfwErrorMsg);

	return glfwErrorMsg;
}
