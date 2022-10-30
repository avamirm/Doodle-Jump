#include"jumpable.hpp"
using namespace std;

Jumpable::Jumpable(int xx,int yy, string type_,int width,int height)
{
	x=xx;
	y=yy;
    jumpable_type = type_;
	jumpable_width = width;
	jumpable_height = height;
	does_go_right = true;
	is_broken = false;
	stage = 0;
	v=0;
}
void Jumpable::draw_jumpable(Window* win, int screen_change)
{
	if(jumpable_type=="platform")
		win->draw_img(NORMAL_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));
	else if(jumpable_type=="mplatform")
		win->draw_img(MOVING_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));	
	else if(jumpable_type=="spring")
		win->draw_img(SPRING,Rectangle(x,WINDOW_HEIGHT-(y+SPRING_HEIGHT- screen_change ),SPRING_WIDTH,SPRING_HEIGHT));	
	else if(jumpable_type=="bplatform")
	    draw_breaking_plat(win,screen_change);	
}
void Jumpable::draw_breaking_plat(Window* win, int screen_change)
{
	if(is_broken)
	{ 
		stage++;
		if(stage < 4)
			win->draw_img(BREAKING_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));		
        else if( stage < 7)
			win->draw_img(BREAKING1_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));		
        else if(stage < 10)
			win->draw_img(BREAKING2_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));	
		else if( stage < 13)
			win->draw_img(BREAKING3_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));		   	
	}
	else
		win->draw_img(BREAKING_PLAT,Rectangle(x,WINDOW_HEIGHT-(y+PLAT_HEIGHT- screen_change ),PLAT_WIDTH,PLAT_HEIGHT));
}
void Jumpable::move_platform()
{
	if(jumpable_type == "mplatform")
	{
		if((x+40) >400)
		  does_go_right = false;
		if(x<0)
		  does_go_right=true;
		if(does_go_right)
		  x = x+3;
		else
		  x = x-3;  
	}
}
std::string Jumpable::get_type()
{
	return jumpable_type; 
}
int Jumpable::get_x()
{ 
	return x; 
}
int Jumpable::get_y()
{ 
	return y; 
}
int Jumpable::get_width()
{ 
	return jumpable_width; 
}
int Jumpable::get_height()
{ 
	return jumpable_height; 
}
void Jumpable::change_is_broken()
{
	is_broken = true;
}