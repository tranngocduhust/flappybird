#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include"base_object.h"

class text_object_ :public base_object{
private:
	string name_text_;
	SDL_Color color_text_;
public:
	enum type_color
	{
		BLACK,
		WHILE,
		RED,
		BLUDE,
		BROWN,
		ORANGE,

	};
	text_object_();
	~text_object_();

	void set_name_text(const string& name) { name_text_ = name; }
	void set_color_text_(const int& col);

	void show_text_on_screen(TTF_Font* fon, SDL_Surface* des);
};
#endif ;