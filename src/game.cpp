#include "game.hpp"

namespace doomLike {
	Game::Game() : window(nullptr), prevFrame(Clock::from_time_t(0)) {
	}

	Game::~Game() {
		delete window;
	}

	void Game::run() {
		if (prevFrame == Clock::from_time_t(0))
			prevFrame = Clock::now();

		while (!window->shouldClose()) {
			Time now = Clock::now();
			update((now - prevFrame).count());
			prevFrame = now;

			window->preDraw();
			draw();
			window->postDraw();
		}
	}
}