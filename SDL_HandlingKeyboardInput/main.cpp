#include <iostream>
#include <stdio.h>
#include <SDL.h>
#undef main

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool init(); // start SDL AND Create main window

bool loadMedia(); // load needed media files

void close(); // close sdl

SDL_Surface *loadSurface( std::string path ); // load indiviual image

SDL_Window *gWindow = NULL; // window we will render to

SDL_Surface *gScreenSurface = NULL; // the actual surface on which we draw

// images that correspond to a key press
SDL_Surface *gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL]; // represents 5 due to enum default K:v, v starts at 0


SDL_Surface *gCurrentSurface = NULL; // Current displayed img

bool init()
{
    bool success = true;

    if (SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf(" SDL could not initialize! SDL Errors : %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("SDL Tutorial ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created %s \n", SDL_GetError());
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;

}

bool loadMedia()
{
    bool success = true;

    // default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT] = loadSurface("C:/Users/ashis/Downloads/04_key_presses/04_key_presses/press.bmp"); // create a surface on the window
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf("Failed to load img \n");
        success = false;
    }

    // default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP] = loadSurface("C:/Users/ashis/Downloads/04_key_presses/04_key_presses/up.bmp"); // create a surface on the window
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP] == NULL)
    {
        printf("Failed to load img \n");
        success = false;
    }

    // default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN] = loadSurface("C:/Users/ashis/Downloads/04_key_presses/04_key_presses/down.bmp"); // create a surface on the window
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL)
    {
        printf("Failed to load img \n");
        success = false;
    }

    // default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface("C:/Users/ashis/Downloads/04_key_presses/04_key_presses/left.bmp"); // create a surface on the window
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL)
    {
        printf("Failed to load img \n");
        success = false;
    }

    // default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface("C:/Users/ashis/Downloads/04_key_presses/04_key_presses/right.bmp"); // create a surface on the window
    if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL)
    {
        printf("Failed to load img \n");
        success = false;
    }

    return success;
}

void close()
{
    // deallocate surfaces
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
        SDL_FreeSurface(gKeyPressSurfaces[ i ]);
        gKeyPressSurfaces[ i ] = NULL;
    }

    // destory window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

SDL_Surface *loadSurface(std::string path)
{
    SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadSurface == NULL)
    {
        printf("Unable to load img %s SDL Error: %s \n", path.c_str(), SDL_GetError());
    }

    return loadedSurface;
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
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Set default current surface
            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                            break;

                            case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                            break;

                            case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                            break;

                            case SDLK_RIGHT:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                            break;

                            default:
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                            break;
                        }
                    }
                }

                //Apply the current image
                SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );

                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
