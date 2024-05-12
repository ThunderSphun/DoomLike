#include <iostream>

#include "game.hpp"
#include "impl/glfw_glew_window.hpp"

class game : public doomLike::Game {
public:
	void init() override {
		window = dynamic_cast<doomLike::Window*>(new doomLike::GLFW_GLEW_Window());
		if (!window) {
			std::cerr << "could not create a window instance" << std::endl << "exiting" << std::endl;
			exit(-1);
		}
		window->init("doom-like", {480, 360});

		window->setClearColor({0.8, 0.8, 1, 1});
	}

	void update(float deltaTime) override {
		if(rand() % 10 == 0) {
			window->setClearColor({rand() / float(RAND_MAX), rand() / float(RAND_MAX), rand() / float(RAND_MAX), 1});
		}
	}

	void draw() override {

	}
};

int main() {
	game game;

	game.init();
	game.run();
	game.shutdown();

	return 0;
}
