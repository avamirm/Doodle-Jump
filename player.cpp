#include"player.hpp"

Player::Player(int yy, Window* window)
{
	y=yy;
	vy=INITIAL_SPEED;
	vx=0;
	x=(WINDOW_WIDTH/2)-(PLAYER_WIDTH/2);
    win = window;
}
void Player::draw_player(bool is_head_right,int screen_change)
{
	if(is_head_right)
	   win->draw_img(RIGHT_PLAYER,Rectangle(x,WINDOW_HEIGHT-(y-screen_change ),PLAYER_WIDTH,PLAYER_HEIGHT));
	else
	   win->draw_img(LEFT_PLAYER,Rectangle(x,WINDOW_HEIGHT-(y- screen_change),PLAYER_WIDTH,PLAYER_HEIGHT));  
}
void Player::checking_range()
{
	x=x+vx;
	if(x>WINDOW_WIDTH)
	  x=0;
	if(x<0)
	  x=WINDOW_WIDTH;  
}
bool Player::does_press_key(Event event)
{
	if(event.get_type() == Event::QUIT) 
      exit(0);
    if(event.get_type() == Event::KEY_PRESS ) 
	   return true;
	if(event.get_type() == Event::KEY_RELEASE) 
	{
	  vx=0;
	  return false;
	}
	else 
	   return false;
}
void Player::horizonal_move(bool& is_head_right, int screen_change)
{
   while(win->has_pending_event())
    { 
	  char pressed_char;Event event= win->poll_for_event();
	  bool is_held = does_press_key(event);	  
	  if(is_held)
	  {
       pressed_char = event.get_pressed_key();
       if (pressed_char == 'd') 
		 change_horizonal_loc(1,is_head_right,screen_change);
       if(pressed_char == 'a')
		change_horizonal_loc(0,is_head_right,screen_change);
	  }  
	}
	checking_range();
}
void Player::change_horizonal_loc(bool a,bool& is_head_right,int screen_change)
{	
	if(a)
	{
	 is_head_right=true;
	 vx = 7;
	 win->draw_img(RIGHT_PLAYER,Rectangle(x,WINDOW_HEIGHT-(y- screen_change ),PLAYER_WIDTH,PLAYER_HEIGHT));
	}
	else
	{
	  is_head_right=false;
	  vx = -7;
	  win->draw_img(LEFT_PLAYER,Rectangle(x,WINDOW_HEIGHT-(y- screen_change ),PLAYER_WIDTH,PLAYER_HEIGHT));
	}
}
void Player::update_location(bool& is_end_game,int screen_change)
{
	y = y+(vy*0.02);
	vy = vy-(1000*0.02);
	if(y-screen_change<0)
	  is_end_game = true;
}

bool Player::is_on_jumpable()
{
  if(((vy==0) || vy<0)
	&&(x<(jumpable_->get_x())+(jumpable_->get_width())-25) 
	&&((x+(PLAYER_WIDTH-25))>(jumpable_->get_x()))
	&&((y-PLAYER_HEIGHT)>jumpable_->get_y())
	&&(((y-PLAYER_HEIGHT)<((jumpable_->get_y()) + (jumpable_->get_height())))))
	return true;
  else
    return false;
}
int Player::player_jump(Jumpable* jumpable)
{
	set_jumpable(jumpable);
	if(is_on_jumpable())
	{
		if(jumpable_->get_type()!="bplatform" && jumpable_->get_type()!="spring")
		{
			vy=INITIAL_SPEED;
			return 1;
		}
		else if(jumpable_->get_type()=="spring")
		{
           vy= 2*INITIAL_SPEED;
		   return 2;
		}
		else 
		   return 0;
	}
	else
	  return -1;
}
bool Player::does_hit_enemy()
{
	if(x<(enemy_->get_x())+(ENEMY_WIDTH) 
	&&((x+(PLAYER_WIDTH))>(enemy_->get_x()))
	&&(y>enemy_->get_y()+20)
	&&(((y-PLAYER_HEIGHT)<((enemy_->get_y()) + ENEMY_HEIGHT))))
	  return true;
	return false;  
}
void Player::set_jumpable(Jumpable* jumpable)
{ 
	jumpable_= jumpable; 
}
void Player::set_enemy(Enemy* enemy)
{ 
	enemy_ = enemy; 
}
int Player::get_y()
{ 
	return y;
}
int Player::get_x()
{
	 return x;
}
int Player::get_vy()
{
	return vy; 
}	