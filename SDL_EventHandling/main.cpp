#include <iostream>
#include <SDL.h>
#include <stdio.h>

#undef main

using namespace std;

string imgPath = "C:/Users/ashis/Downloads/03_event_driven_programming/03_event_driven_programming/x.bmp";

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


// Start up SDL --> Step 1
bool init();

// loads Media --> Needed external files
bool loadMedia();

// Free media and close SDL --> Return all memory
void close();


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;


bool init()
{
    bool success = true; // flag

    if (SDL_Init( SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL Could not init %s \n", SDL_GetError());
        success =  false;
    }
    else
    {
        gWindow = SDL_CreateWindow("SDL Events Handling", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created %s \n", SDL_GetError());
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;

    gXOut = SDL_LoadBMP("C:/Users/ashis/Downloads/03_event_driven_programming/03_event_driven_programming/x.bmp");
    if (gXOut == NULL)
    {
        printf("SDL CANNOT LOAD IMAGE \n");
        success = false;

    }
    return success;
}

void close()
{
    SDL_FreeSurface(gXOut);
    gXOut = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

int main(int argc, char *argv[])
{
    if (!init())
    {
        printf("Failed to int \n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load Media \n");
        }
        else
        {
            bool quit = false;

            SDL_Event e;

            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                SDL_BlitSurface(gXOut,NULL, gScreenSurface, NULL);

                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }

    close();
    return 0;

}












