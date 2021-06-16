#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, Python &python) const;

 private:
  void ChangeDirection(Python &python, Python::Direction input,
                       Python::Direction opposite) const;
};

#endif