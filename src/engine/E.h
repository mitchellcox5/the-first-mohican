#ifndef ENGINERESOURCES_H
	#define ENGINERESOURCES_H

#include <SDL2/SDL.h>


#ifdef APPLE
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#elif LINUX
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#elif WIN32
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#endif

#include <string>
#include "FPS.h"
#include "AppState.h"
#include "Texture.h"
#include "Text.h"
#include "Logger.h"
#include "Configuration.h"

class EngineResources {
	public:
		// Initialization functions
		EngineResources();
		void Start();
		void Quit();
		void SetActiveAppState(int App);
		void SetWindowResolution(int x, int y);
		int GetWindowWidth();
		int GetWindowHeight();

		bool running;
		SDL_Window* gameWindow;
		SDL_Renderer* gameRenderer;
		SDL_Surface* gameSurface;
		Logger* logger;
		Configuration* configs;
		FPS fps;
		AppState* appState;
	private:
		int windowHeight;
		int windowWidth;
};

extern EngineResources E;

#endif
