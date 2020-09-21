#ifndef PLUMBER_OBJECT_H_
#define PLUMBER_OBJECT_H_

#include"base_object.h"

class Plumber_object_ :public base_object {
private:
	int x_val_;
	int y_val_;
	bool is_type_;

public:
	Plumber_object_();
	~Plumber_object_();

	void Handle_Move_(const int&x_);	

	void Set_is_type(const bool& is_) { is_type_ = is_; }
	bool Get_is_type() { return is_type_; }
};

#endif // !PLUMBER_OBJECT_H_
