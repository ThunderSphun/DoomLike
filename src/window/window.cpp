#include "window.hpp"

bool doomLike::Window::shouldClose() const {
	return closing;
}
