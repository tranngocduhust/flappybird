#include"text_object.h"

text_object_::text_object_() {
	//
}
text_object_ ::~text_object_() {
	//
}

void text_object_::set_color_text_(const int& col) {
	if (col == BLACK) {
		color_text_ = { 0,0,0 };
	}
	else if (col == WHILE) {
		color_text_ = { 255,255,255 };
	}
	else if (col == RED) {
		color_text_ = { 255,0,0 };
	}
	else if (col == BLUDE) {
		color_text_ = { 0,255,64 };
	}
	else if (col == BROWN) {
		color_text_ = { 232,0,35 };
	}
	else if (col == ORANGE) {
		color_text_ = { 255,137,29 };
	}
}

void text_object_::show_text_on_screen(TTF_Font* font, SDL_Surface* des) {
	Image_ = TTF_RenderText_Solid(font, name_text_.c_str(), color_text_);
	show_Image(des);
}