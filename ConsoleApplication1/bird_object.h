#ifndef BIRD_OBJECT_H_
#define BIRD_OBJECT_H_

#include"base_object.h"

class bird_object_ :public base_object {
private:
	int x_val_;
	int y_val_;
	int v0_;
	bool is_move_;
	
public:
	bird_object_();
	~bird_object_();

	void Handle_Move_(const int&t);
	void Handle_Event_(SDL_Event &event_);

	bool Get_is_move_() { return is_move_; }
};


#endif // !BIRD_OBJECT_H_
