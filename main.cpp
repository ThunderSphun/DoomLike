#include <iostream>
#include <GLFW/glfw3.h>

int main() {
	if (!glfwInit()) {
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(480, 360, "test", nullptr, nullptr);
	if (!window){
		glfwTerminate();
		return -1;
	}
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
