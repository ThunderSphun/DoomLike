#pragma once
#include "window.hpp"

#include <chrono>

using Clock = std::chrono::system_clock;
using Time = std::chrono::time_point<Clock, std::chrono::duration<float>>;

namespace doomLike {
	class Game {
	public:
		Game();
		~Game();

		virtual void init() {};
		virtual void shutdown() {};
		virtual void run();

	protected:
		Window* window;

		virtual void update(float deltaTime) {};
		virtual void draw() {};

	private:
		Time prevFrame;
	};
}