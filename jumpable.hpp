#ifndef JUMPABLE
#define JUMPABLE

#include<string>
#include"rsdl.hpp"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 640
#define PLAT_WIDTH 75
#define PLAT_HEIGHT 22
#define SPRING_WIDTH 35
#define SPRING_HEIGHT 29
#define NORMAL_PLAT "normal_platform.png"
#define MOVING_PLAT "moving_platform.png"
#define BREAKING_PLAT "breaking_platform.png"
#define BREAKING1_PLAT "breaking1.png"
#define BREAKING2_PLAT "breaking2.png"
#define BREAKING3_PLAT "breaking3.png"
#define SPRING "spring.png"

class Jumpable
{
  public:
    Jumpable(int xx,int yy,std::string type_,int width,int height);
	void draw_jumpable(Window* win, int screen_change);
	void move_platform();
	std::string get_type();
	int get_x();
	int get_y();
	int get_width();
	int get_height();
	void change_is_broken();
	void draw_breaking_plat(Window* win, int screen_change);

  private:
    int x;
    int y;
    int v;
	bool does_go_right;
    std::string jumpable_type;
	int jumpable_width;
	int jumpable_height;
	int stage;
	bool is_broken;
};
#endif
