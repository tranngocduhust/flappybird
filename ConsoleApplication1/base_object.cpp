#include"base_object.h"

base_object::base_object() {
	Image_ = NULL;
	Rect_.x = 0;
	Rect_.y = 0;
}
base_object::~base_object() {
	// to do
}
bool base_object::Load_Image_(string file_path) {
	Image_ = SDL_common_Function::Load_Image(file_path);
	if (Image_ == NULL) {
		return false;
	}
	return true;
}
void base_object::show_Image(SDL_Surface* des) {
	SDL_common_Function::Apply_Image(Image_, des, Rect_.x, Rect_.y);
}
void base_object::Set_Rect_(const int& x, const int& y) {
	Rect_.x = x;
	Rect_.y = y;
}
void base_object::Show_Clip_Frame_(SDL_Surface* des, SDL_Rect&off) {
	Rect_=SDL_common_Function::Apply_Clip(Image_, des, off, Rect_.x, Rect_.y);
}