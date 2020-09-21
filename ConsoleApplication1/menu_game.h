#ifndef MENU_GAME_H_
#define MENU_GAME_H_
#include"text_object.h"

class menu_game_ :public text_object_ {
private:
	int chose_;
public:
	enum chose_type
	{
		PLAY,
		EXIT,
	};

	menu_game_();
	~menu_game_();
	int Handle_Move_Mouse_(SDL_Surface* des, TTF_Font* font);

	int Show_Tutorial_(SDL_Surface* des, TTF_Font* font);
	int About_game_(SDL_Surface* des, TTF_Font* font);
	int Game_over(SDL_Surface* des, TTF_Font* font, const int& mark, const int& time);
};

#endif // !MENU_GAME_H_
