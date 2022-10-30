#include "enemy.hpp"

Enemy::Enemy(int xx,int yy)
{
	x = xx;
	y = yy;
}
void Enemy::draw_enemy(Window* win,int screen_change)
{
	win->draw_img(ENEMY,Rectangle(x,WINDOW_HEIGHT-(y+ENEMY_HEIGHT- screen_change ),ENEMY_WIDTH,ENEMY_HEIGHT));
}
int Enemy::get_x()
{ 
	return x; 
}
int Enemy::get_y()
{
	return y; 
}
