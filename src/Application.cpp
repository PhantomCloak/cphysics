#include "Application.h"

void Application::Setup()
{
    appRunning = Graphics::OpenWindow();
}

bool Application::IsRunning()
{
    return appRunning;
}
void Application::Input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
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

void Application::Update()
{
    Graphics::ClearScreen(0xFFFFFFFF);

    static int timePreviousFrame;
    int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - timePreviousFrame);
    if (timeToWait > 0)
        SDL_Delay(timeToWait);

    Graphics::DrawCircle(500,500,40,0,0xffff0000);

    timePreviousFrame = SDL_GetTicks();
}

void Application::Render()
{
    Graphics::RenderFrame();
}

void Application::Destroy()
{

}
