#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Python &python, Python::Direction input,
                                 Python::Direction opposite) const {
  if (python.direction != opposite || python.size == 1) python.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Python &python) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(python, Python::Direction::kUp,
                          Python::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(python, Python::Direction::kDown,
                          Python::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(python, Python::Direction::kLeft,
                          Python::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(python, Python::Direction::kRight,
                          Python::Direction::kLeft);
          break;
      }
    }
  }
}