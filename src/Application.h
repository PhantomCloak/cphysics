#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
    private:
        bool isDebug;
        bool appRunning;
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
