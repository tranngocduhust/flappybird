#include"bird_object_.h"

bird_object_::bird_object_() {
	x_val_ = 0;
	y_val_ = Y0_BIRD;
	v0_ = 0;
	t_ = 0;
	a_ = -0.5;
	is_move_ = true;

	frame_[0].x = 0;
	frame_[0].y = 0;
	frame_[0].w = 34;
	frame_[0].h = 24;

	frame_[1].x = 34;
	frame_[1].y = 0;
	frame_[1].w = 34;
	frame_[1].h = 24;
	
	frame_[2].x = 68;
	frame_[2].y = 0;
	frame_[2].w = 34;
	frame_[2].h = 24;

	
}
bird_object_::~bird_object_() {
	//to do
}

void bird_object_::Handle_Move_() {
	a_ = a_ + 0.4;
	t_ = int(a_);

	Rect_.y = y_val_ - v0_ * t_ + 0.5*A_BIRD * t_ * t_;

	if (Rect_.y == 0 || Rect_.y >= 608) {
		is_move_ = false;
	}
}
void bird_object_::Handle_Event_(SDL_Event& event_, Mix_Music* Wing) {
	if (event_.type == SDL_MOUSEBUTTONDOWN) {
		if (event_.button.button == SDL_BUTTON_LEFT) {
			y_val_ = Rect_.y;
			v0_ = V0_BIRD;
			a_ = -0.4;
			Mix_PlayMusic(Wing, 0);
		}
	}
	
}
