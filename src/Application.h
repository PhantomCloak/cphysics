#ifndef APPLICATION_H
#define APPLICATION_H

#include "Graphics.h"
#include "Physics/World.h"

#define MILLISECS_PER_FRAME 16
class Application {
private:
  bool isDebug;
  bool appRunning;
  World *world;

public:
  Application() = default;
  ~Application() = default;

  bool IsRunning();
  void Setup();
  void Input();
  void Update();
  void Render();
  void Destroy();
};
#endif // !APPLICATION_H
