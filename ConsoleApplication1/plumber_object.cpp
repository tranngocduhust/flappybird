#include"plumber_object.h"

Plumber_object_::Plumber_object_() {
	x_val_ = 0;
	y_val_ = 0;
}
Plumber_object_ ::~Plumber_object_() {

}

void Plumber_object_::Handle_Move_(const int& x_) {
	Rect_.x = Rect_.x - SPEED_PLUMBER;
	if (Rect_.x <= -WIDTH_PLUMBER) {
		Rect_.x = WIDTH_SCREEN + WIDTH_PLUMBER;
		int tem = 0 + rand() % 381;
		if (is_type_  == true) {
			Rect_.y = -400 + tem;
		}
		else {
			Rect_.y = x_ + SPACE_PLUMBER;
		}
	}
}