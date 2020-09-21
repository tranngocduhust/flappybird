#include"common_function.h"
#include"plumber_object.h"
#include"bird_object_.h"
#include"text_object.h"
#include"menu_game.h"

TTF_Font* Font = NULL;
int _test = 5;
bool INIT() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	SDL_WM_SetCaption("Flappy Bird", "Icon");
	g_Screen = SDL_SetVideoMode(480, 720, 32, SDL_SWSURFACE);
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		return false;
	}
	g_Wing = Mix_LoadMUS("wing.ogg");
	g_Hit = Mix_LoadWAV("hit.wav");
	g_Point = Mix_LoadWAV("point.ogg");
	if (g_Wing == NULL || g_Hit == NULL||g_Point==NULL) {
		return false;
	}
	if (TTF_Init() == -1) {
		return false;
	}
	Font = TTF_OpenFont("font.ttf", 20);
	if (Font == NULL) {
		return false;
	}
	return true;
}
void CLEAR();

int main() {
	do {

		int _test = 10;
		bool _check_ = false;
		bool is_quit = false;
		int _X0_Background = X0;
		int _X0_Ground = X0;
		int fr = 0;
		float _tem_fr = 0;
		int point = 0;
		bool check = false;
		if (INIT() == false) {
			return 1;
		}


		g_Image = SDL_common_Function::Load_Image("bg.png");
		g_Ground = SDL_common_Function::Load_Image("ground.png");
		if (g_Image == NULL) {
			return 1;
		}
		SDL_common_Function::Apply_Image(g_Image, g_Screen, X0, Y0);
		Plumber_object_ _plumber_1[2];
		Plumber_object_ _plumber_2[2];
		for (size_t i = 0; i < 2; i++)
		{
			int _y_plumber = 0 + rand() % 381;
			_plumber_1[i].Set_Rect_(WIDTH_SCREEN + i * SPACE_WIDTH_PLUMBER, -400 + _y_plumber);
			_plumber_1[i].Load_Image_("plumber1.png");
			_plumber_1[i].Set_is_type(true);
			_plumber_2[i].Set_Rect_(WIDTH_SCREEN + i * SPACE_WIDTH_PLUMBER, _y_plumber + SPACE_PLUMBER);
			_plumber_2[i].Load_Image_("plumber2.png");
			_plumber_2[i].Set_is_type(false);
		}
		bird_object_ _flappy;
		_flappy.Load_Image_("flappy.png");
		_flappy.Set_Rect_(X0_BIRD, Y0_BIRD);

		text_object_ _Text;

		menu_game_ _menu;

		int _check = _menu.Handle_Move_Mouse_(g_Screen,Font);
		if (_check == 3) {
			return 1;
		}
		else if (_check == 0) {
			is_quit = false;
		}
		while (!is_quit)
		{
			SDL_common_Function::Apply_Image(g_Image, g_Screen, _X0_Background, Y0);
			SDL_common_Function::Apply_Image(g_Image, g_Screen, _X0_Background + WIDTH_SCREEN, Y0);
			_X0_Background -= SPEED_BACKGROUND;
			_X0_Ground -= SPEED_GROUND;
			if (_X0_Background <= -WIDTH_SCREEN || _X0_Ground <= -WIDTH_SCREEN) {
				_X0_Background = 0;
				_X0_Ground = 0;
			}


			while (SDL_PollEvent(&g_Event))
			{
				if (g_Event.type == SDL_QUIT) {
					is_quit = true;
					break;
				}
				_flappy.Handle_Event_(g_Event, g_Wing);
			}
			_flappy.Handle_Move_();

			_flappy.Show_Clip_Frame_(g_Screen, _flappy.Get_frame()[fr]);
			fr++;
			if (fr >= 3) {
				fr = 0;

			}

			for (size_t pl = 0; pl < 2; pl++)
			{
				_plumber_1[pl].Handle_Move_(pl * 2 + 2);
				_plumber_1[pl].show_Image(g_Screen);

				_plumber_2[pl].Handle_Move_(_plumber_1[pl].Get_Rect_().y + HEIGHT_PLUMBER_1);
				_plumber_2[pl].show_Image(g_Screen);

				if (SDL_common_Function::CheckCollistion(_flappy.Get_Rect_(), _plumber_1[pl].Get_Rect_(), _plumber_2[pl].Get_Rect_()) == true) {
					Mix_PlayChannel(1, g_Hit, 0);
					_check_ = true;
					break;
				}
				if (SDL_common_Function::CheckPoint(_flappy.Get_Rect_(), _plumber_1[pl].Get_Rect_(), _plumber_2[pl].Get_Rect_()) == true) {
					check = true;
					Mix_PlayChannel(-1, g_Point, 0);
				}
				

			}
			SDL_common_Function::Apply_Image(g_Ground, g_Screen, _X0_Ground, Y0_GROUND);
			SDL_common_Function::Apply_Image(g_Ground, g_Screen, _X0_Ground + WIDTH_SCREEN, Y0_GROUND);
			if (check == true) {
				point++;
				check = false;
			}
			string Point = "Point: ";
			string Tem = Point + to_string(point);

			_Text.set_name_text(Tem);
			_Text.Set_Rect_(240, 680);
			_Text.set_color_text_(text_object_::BLACK);
			_Text.show_text_on_screen(Font, g_Screen);
			if (_check_ == true) {
				int check_game_over = 10;
				check_game_over = _menu.Game_over(g_Screen, Font, point, 0);
				if (check_game_over == 0)
				{
					is_quit = true;
					_test = 1;

					break;
				}
				else if (check_game_over == 1) {
					is_quit = true;
					_test = 0;

					break;
				}
			}
			SDL_Flip(g_Screen);


		}

	}while (_test);
	CLEAR();
	return 0;

}

void CLEAR() {
	SDL_FreeSurface(g_Image);
	SDL_FreeSurface(g_Screen);
	SDL_Quit();
}