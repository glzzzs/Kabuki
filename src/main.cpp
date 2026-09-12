// In main.cpp
#include "KiApp.h"

int main(int, char**) 
{
    ki::App app;
    app.onInit();

    while (app.isRunning()) 
    {
        app.onFrame();
    }
    app.onExit();

    return 0;
}