#include"common_function.h"

SDL_Surface* SDL_common_Function::Load_Image(string file_path) {
	SDL_Surface* Image = NULL;
	SDL_Surface* Optimize = NULL;
	Image = IMG_Load(file_path.c_str());
	if (Image != NULL) {
		Optimize = SDL_DisplayFormat(Image);
		if (Optimize != NULL) {
			UINT32 color_key = SDL_MapRGB(Optimize->format, 0, 255, 255);
			SDL_SetColorKey(Optimize, SDL_SRCCOLORKEY, color_key);
		}
		SDL_FreeSurface(Image);
	}
	return Optimize;
}
SDL_Rect SDL_common_Function::Apply_Image(SDL_Surface* src, SDL_Surface* des, const int& x, const int &y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
	return offset;
}
SDL_Rect SDL_common_Function::Apply_Clip(SDL_Surface* src, SDL_Surface* des, SDL_Rect& Off, const int& x, const int& y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, &Off, des, &offset);
	return offset;
}
bool SDL_common_Function::CheckCollistion(const SDL_Rect& bird, const SDL_Rect& plumber_1,const SDL_Rect& plumber_2) {
	int Left_b = bird.x;
	int Right_b = bird.x + bird.w;
	int Top_b = bird.y;
	int Button_b = bird.y + bird.h;

	int Left_p_1 = plumber_1.x;
	int Right_p_1 = plumber_1.x + WIDTH_PLUMBER;
	int Top_p_1 = 0;
	int Button_p_1 = plumber_1.y+HEIGHT_PLUMBER_1;

	int Left_p_2 = plumber_2.x;
	int Right_p_2 = plumber_2.x + WIDTH_PLUMBER;
	int Top_p_2 = plumber_2.y;
	int Button_p_2 = 608;

	if (Top_b < Button_p_1 && Left_b<Right_p_1 && Right_b>Left_p_1) {
		return true;
	}
	if (Button_b > Top_p_2 && Left_b<Right_p_2 && Right_b>Left_p_2) {
		return true;
	}
	if (Top_b <= 0 || Button_b >= 608) {
		return true;
	}
	return false;
}

bool SDL_common_Function::CheckPoint(const SDL_Rect& bird, const SDL_Rect& plumber_1, const SDL_Rect& plumber_2) {
	int Left_b = bird.x;
	int Right_b = bird.x + bird.w;
	int Top_b = bird.y;
	int Button_b = bird.y + bird.h;

	int Left_p_1 = plumber_1.x;
	int Right_p_1 = plumber_1.x + WIDTH_PLUMBER;
	int Top_p_1 = 0;
	int Button_p_1 = plumber_1.y + HEIGHT_PLUMBER_1;

	int Left_p_2 = plumber_2.x;
	int Right_p_2 = plumber_2.x + WIDTH_PLUMBER;
	int Top_p_2 = plumber_2.y;
	int Button_p_2 = 608;
	if (Right_b >= Left_p_1 && Left_p_1+SPEED_PLUMBER>Right_b) {
		return true;
	}
	return false;
}
bool SDL_common_Function::check_colision_menu(const SDL_Rect& rect, const int& x, const int& y) {
	if (x >= rect.x && x <= rect.x + rect.w && y > rect.y && y < rect.y + rect.h) {
		return true;
	}
	return false;
}