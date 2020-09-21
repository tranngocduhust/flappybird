#include"bird_object.h"

bird_object_::bird_object_() {
	x_val_ = 0;
	y_val_ = Y0_BIRD;
	v0_ = 0;
	is_move_ = true;
}
bird_object_::~bird_object_() {
	//to do
}

void bird_object_::Handle_Move_(const int &t) {
	Rect_.y = y_val_ - v0_ * t + A_BIRD * t * t;
	if (Rect_.y == 0 || Rect_.y >= 608) {
		is_move_ = false;
	}
}
void bird_object_::Handle_Event_(SDL_Event& event_) {
	if (event_.type == SDL_MOUSEBUTTONDOWN) {
		if (event_.button.button == SDL_BUTTON_LEFT) {
			y_val_ = Rect_.y;
			v0_ = V0_BIRD;
		}
	}
	else
	{
		v0_ = 0;
	}
}