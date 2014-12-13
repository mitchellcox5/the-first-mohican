#include "E.h"

EngineResources E;

EngineResources::EngineResources() {
  running = true;
  gameWindow = NULL;
  gameRenderer = NULL;
  gameSurface = NULL;

  windowWidth = 640;
  windowHeight = 480;
}

bool EngineResources::Start() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return false;
  }
  
  // Declare our window
  gameWindow = SDL_CreateWindow("11th-fret Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
  if(gameWindow == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  // Declare our Renderer
  gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
  if (gameRenderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }
  
  gameSurface = SDL_GetWindowSurface(gameWindow);
  // Welp, looks like everything is good
  std::cout << "hey everything initialized" << std::endl;
  return true;
}

void EngineResources::Quit() {
  SDL_FreeSurface(gameSurface);
  SDL_DestroyRenderer(gameRenderer);
  SDL_DestroyWindow(gameWindow);
  SDL_Quit();
  running = false;
}

void EngineResources::SetWindowResolution(int x, int y) {
  windowWidth = x;
  windowHeight = y;
}

int EngineResources::GetWindowWidth(){
  return windowWidth;
}

int EngineResources::GetWindowHeight() {
  return windowHeight;
}