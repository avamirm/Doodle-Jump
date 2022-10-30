#ifndef THE_ENEMY
#define THE_ENEMY

#include "rsdl.hpp"

#define ENEMY_WIDTH 85
#define ENEMY_HEIGHT 115
#define ENEMY "enemy.png"
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 640

class Enemy
{
  public:
       Enemy(int xx,int yy);
	   void draw_enemy(Window* win,int screen_change);
	   int get_x();
	   int get_y();
  private:
       int x;
       int y;
};
#endif