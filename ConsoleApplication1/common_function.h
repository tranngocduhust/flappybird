#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<Windows.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

using namespace std;

static SDL_Surface* g_Image = NULL;
static SDL_Surface* g_Screen = NULL;
static SDL_Event g_Event;

static Mix_Music* g_Wing = NULL;
static Mix_Chunk* g_Hit = NULL;
static Mix_Chunk* g_Point = NULL;

#undef main;
//============= Screen================

#define WIDTH_SCREEN 480
#define HEIGHT_SCREEN 720
#define BPP 32

//============ Background ============

const int X0 = 0;
const int Y0 = 0;
const int SPEED_BACKGROUND = 1;
//============= Plumber ==============
const int SPEED_PLUMBER = 1;
const int SPACE_PLUMBER = 140;
const int SPACE_WIDTH_PLUMBER = 292;
const int WIDTH_PLUMBER = 52;
const int HEIGHT_PLUMBER_1 = 400;
const int HEIGHT_PLUMBER_2 = 600;

//============== Ground ==============

static SDL_Surface* g_Ground = NULL;

const int SPEED_GROUND = 1;
const int Y0_GROUND = 608;

//============== Bird ================

const int X0_BIRD = 240;
const int Y0_BIRD = 300;
const int V0_BIRD = 12;
const int A_BIRD = 1;

//====================================

namespace SDL_common_Function {
	SDL_Surface* Load_Image(string file_path);
	SDL_Rect Apply_Image(SDL_Surface* src, SDL_Surface* des,const int &x,const int &y );
	SDL_Rect Apply_Clip(SDL_Surface* src, SDL_Surface* des, SDL_Rect& Off, const int& x, const int& y);
	bool CheckCollistion(const SDL_Rect&bird,const SDL_Rect&plumber_1,const SDL_Rect&plumber_2);
	bool CheckPoint(const SDL_Rect& bird, const SDL_Rect& plumber_1, const SDL_Rect& plumber_2);
	bool check_colision_menu(const SDL_Rect& rect, const int& x, const int& y);
}

#endif // !COMMON_FUNCTION_H_

