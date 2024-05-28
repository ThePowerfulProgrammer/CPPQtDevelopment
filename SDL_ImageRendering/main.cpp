#include <SDL.h>
#include <stdio.h>
#undef main

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// declare a few functions to use later

bool init(); // start  SDL and Create the window
bool loadMedia(); // Loads Media
void close(); // Free Media and shuts down SDL

// Create some bad bad Global Vars

SDL_Window *gWindow = NULL; //Window we render to
SDL_Surface *gScreenSurface = NULL; // the surface of the window
SDL_Surface *gHelloWorld = NULL; // Image we will load and show on the screen

// Define the earlier functions

bool init()
{
    bool success = true;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        printf("SDL Could not init! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create the Window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window can not be created SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Get Window Surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}


bool loadMedia()
{

    bool success = true;

    gHelloWorld = SDL_LoadBMP("C:/Users/ashis/Downloads/02_getting_an_image_on_the_screen/02_getting_an_image_on_the_screen/hello_world.bmp");

    if (gHelloWorld == NULL)
    {
        printf("Unable to load image SDL_Error %2\n", "C:/Users/ashis/Downloads/02_getting_an_image_on_the_screen/02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
    }
    return success;
}

void close()
{
    SDL_FreeSurface( gHelloWorld ); // deallocate surface
    gHelloWorld = NULL;

    SDL_DestroyWindow(gWindow); // destroy window
    gWindow = NULL;

    SDL_Quit(); // quit subsystems
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

            //Update the surface
            SDL_UpdateWindowSurface( gWindow );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}












