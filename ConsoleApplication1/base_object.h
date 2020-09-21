#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include"common_function.h"

class base_object {
protected:
	SDL_Surface* Image_;
	SDL_Rect Rect_;
public:
	base_object();
	~base_object();
	bool Load_Image_(string file_path);
	void show_Image(SDL_Surface* des);

	void Set_Rect_(const int& x, const int& y);
	SDL_Rect Get_Rect_() { return Rect_; }

	void Show_Clip_Frame_(SDL_Surface* des, SDL_Rect&off);
};


#endif // !BASE_OBJECT_H_

