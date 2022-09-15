#include "Application.h"

void Application::Setup() {
  appRunning = Graphics::OpenWindow();
  world = new World(-9.8);
}

bool Application::IsRunning() { return appRunning; }
void Application::Input() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      appRunning = false;
      break;
    case SDL_MOUSEBUTTONDOWN:
      int x, y;
      SDL_GetMouseState(&x, &y);

      if (event.button.button == SDL_BUTTON_LEFT) {

        int randomMass = rand() % 5;
        randomMass = randomMass == 0 ? 1 : randomMass;

        Particle *particle = new Particle(x, y, randomMass);
        world->AddParticle(particle);
      } else if (event.button.button == SDL_BUTTON_RIGHT) {
        Circle *circle = new Circle(x, y, 25, 5);
        world->AddCircle(circle);
      }
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
        appRunning = false;
      if (event.key.keysym.sym == SDLK_a)
        for (auto c : world->GetCircles()) {
          c->AddTorque(15);
        }
      break;
    }
  }
}

void Application::Update() {
  static int timePreviousFrame;
  int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - timePreviousFrame);
  if (timeToWait > 0)
    SDL_Delay(timeToWait);

  float deltaTime = (SDL_GetTicks() - timePreviousFrame) / 1000.0f;
  if (deltaTime > 0.016)
    deltaTime = 0.016;

  timePreviousFrame = SDL_GetTicks();
  world->Update(deltaTime);
}

void Application::Render() {
  Graphics::ClearScreen(0xffffffff);

  for (auto particle : world->GetParticles()) {
    Graphics::DrawFillCircle(particle->position.x, particle->position.y, 2,
                             0xff000000);
  }

  for (auto circle : world->GetCircles()) {
    Graphics::DrawCircle(circle->position.x, circle->position.y, circle->radius,
                         circle->rotation, 0xff000000);
  }

  Graphics::RenderFrame();
}

void Application::Destroy() {}
