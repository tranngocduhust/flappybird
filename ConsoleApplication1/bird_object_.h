#ifndef BIRD_OBJECT__H_
#define BIRD_OBJECT__H_

#include"base_object.h"

class bird_object_ :public base_object {
private:
	int x_val_;
	int y_val_;
	int v0_;
	int t_;
	float a_;
	bool is_move_;
	SDL_Rect frame_[3];

public:
	bird_object_();
	~bird_object_();

	void Handle_Move_();
	void Handle_Event_(SDL_Event& event_,Mix_Music*Wing);

	bool Get_is_move_() { return is_move_; }

   
	SDL_Rect* Get_frame() { return frame_; }
};


#endif // !BIRD_OBJECT__H_


