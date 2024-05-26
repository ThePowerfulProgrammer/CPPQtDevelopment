#include <SDL.h>
#include <stdio.h>
#undef main


// Screen dimension constants --> Window
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{
    // The window we will create and render to
    SDL_Window *window = NULL;

    // The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    // Init SDL
    if ( SDL_Init( SDL_INIT_VIDEO) < 0 )
    {
        printf(" SDL Could not init  SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        // window title, x, y , width, height, window f;ags
        window = SDL_CreateWindow(" Window Title",  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s \n", SDL_GetError());
        }
        else
        {
            // Grab the surface
            screenSurface = SDL_GetWindowSurface( window );

            // color surface
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

            //
            SDL_UpdateWindowSurface( window );

            // hack to keep window up
            SDL_Event e;
            bool quit = false;
            while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }


        }

    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();


    return 0;
}
