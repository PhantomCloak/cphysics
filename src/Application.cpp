#include "Application.h"

void Application::Setup() { appRunning = Graphics::OpenWindow(); }

bool Application::IsRunning() { return appRunning; }
void Application::Input() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      appRunning = false;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
        appRunning = false;
      break;
    }
  }
}

void Application::Update() {
  static int timePreviousFrame;
  int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - timePreviousFrame);
  if (timeToWait > 0)
    SDL_Delay(timeToWait);

  Graphics::DrawCircle(500, 500, 40, 0, 0xff00ffff);
  Graphics::DrawCircle(200, 300, 100, 0, 0xff00ffff);
  Graphics::DrawCircle(1000, 1000, 80, 0, 0xff00ffff);

  timePreviousFrame = SDL_GetTicks();
}

void Application::Render() {
  Graphics::RenderFrame();
  Graphics::ClearScreen(0xFFFFFFFF);
}

void Application::Destroy() {}
